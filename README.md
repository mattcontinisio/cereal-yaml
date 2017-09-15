# cereal-yaml

YAML archive for [cereal](http://USCiLab.github.com/cereal), powered by [yaml-cpp](https://github.com/jbeder/yaml-cpp).

## How to use

* [Set up cereal](http://uscilab.github.io/cereal/quickstart.html)
* Include `include/cereal-yaml/archives/yaml.hpp`
* Link with [yaml-cpp](https://github.com/jbeder/yaml-cpp)

## Example

See `example/example.cpp`

    #include <cereal-yaml/archives/yaml.hpp>
    
    #include <cereal/types/memory.hpp>
    #include <cereal/types/unordered_map.hpp>
    
    #include <fstream>
    
    struct MyRecord
    {
        MyRecord() = default;
        MyRecord(uint8_t x_, uint8_t y_, float z_)
            : x(x_)
            , y(y_)
            , z(z_)
        {}
    
        uint8_t x, y;
        float z = 0;
    
        template <class Archive>
        void serialize(Archive& ar)
        {
            ar(x, y, z);
        }
    
        friend std::ostream& operator<<(std::ostream& os, const MyRecord& myRecord);
    };
    
    inline std::ostream& operator<<(std::ostream& os, const MyRecord& myRecord)
    {
        os << "{";
        os << "x=" << int(myRecord.x) << ",";
        os << "y=" << int(myRecord.y) << ",";
        os << "z=" << myRecord.z;
        os << "}";
        return os;
    }
    
    struct SomeData
    {
        int32_t id;
        std::shared_ptr<std::unordered_map<uint32_t, MyRecord>> data;
    
        template <class Archive>
        void save(Archive& ar) const
        {
            ar(data);
        }
    
        template <class Archive>
        void load(Archive& ar)
        {
            static int32_t idGen = 0;
            id = idGen++;
            ar(data);
        }
    
        friend std::ostream& operator<<(std::ostream& os, const SomeData& someData);
    };
    
    inline std::ostream& operator<<(std::ostream& os, const SomeData& someData)
    {
        os << "{";
        os << "id=" << someData.id << ",";
        os << "data={";
        for (auto entry : *someData.data)
        {
            os << entry.first << ":" << entry.second << ",";
        }
        if (someData.data->size() > 0)
        {
            os << "\b\b";
        }
        os << "}";
        os << "}";
        return os;
    }
    
    int main()
    {
        std::ostringstream os;
        {
            cereal::YAMLOutputArchive archive(os);
            SomeData myData;
            myData.id = 5;
            myData.data = std::make_shared<std::unordered_map<uint32_t, MyRecord>>();
            myData.data->emplace(1, MyRecord{1, 2, 3.0});
            myData.data->emplace(2, MyRecord{4, 5, 6.1});
            std::cout << "myData=" << myData << std::endl;
            archive(myData);
        }
        std::cout << "output=\n" << os.str() << std::endl;
    
        std::istringstream is(os.str());
        {
            cereal::YAMLInputArchive archive(is);
            SomeData myData;
            archive(myData);
            std::cout << "myData=" << myData << std::endl;
        }
    
        return 0;
    }

    
Output:

    myData={id=5,data={2:{x=4,y=5,z=6.1},1:{x=1,y=2,z=3}}
    output=
    value0:
      value0:
        ptr_wrapper:
          id: 2147483649
          data:
            - key: 2
              value:
                value0: 4
                value1: 5
                value2: 6.099999904632568
            - key: 1
              value:
                value0: 1
                value1: 2
                value2: 3
    myData={id=0,data={1:{x=1,y=2,z=3},2:{x=4,y=5,z=6.1}}

    