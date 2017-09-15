/*
  Copyright (c) 2017, Matt Continisio
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of cereal nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL RANDOLPH VOORHIES AND SHANE GRANT BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "yaml.hpp"

#include "common.hpp"
#include "array.hpp"
#include "basic_string.hpp"
#include "bitset.hpp"
#include "boost_variant.hpp"
#include "chrono.hpp"
#include "complex.hpp"
#include "deque.hpp"
#include "forward_list.hpp"
#include "list.hpp"
#include "load_construct.hpp"
#include "map.hpp"
#include "memory_cycles.hpp"
#include "memory.hpp"
#include "multimap.hpp"
#include "multiset.hpp"
#include "pair.hpp"
#include "pod.hpp"
#include "polymorphic.hpp"
#include "priority_queue.hpp"
#include "queue.hpp"
#include "set.hpp"
#include "stack.hpp"
#include "structs_minimal.hpp"
#include "structs_specialized.hpp"
#include "structs.hpp"
#include "tuple.hpp"
#include "unordered_loads.hpp"
#include "unordered_map.hpp"
#include "unordered_multimap.hpp"
#include "unordered_multiset.hpp"
#include "unordered_set.hpp"
#include "user_data_adapters.hpp"
#include "valarray.hpp"
#include "vector.hpp"
#include "versioning.hpp"

#include <cereal-yaml/archives/yaml.hpp>

TEST_CASE("yaml_array")
{
  test_array<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_string_basic")
{
  test_string_basic<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_bitset")
{
  test_bitset<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_boost_variant")
{
  test_boost_variant<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_chrono")
{
  test_chrono<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_complex")
{
  test_complex<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_deque")
{
  test_deque<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_forward_list")
{
  test_forward_list<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_list")
{
  test_list<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_memory_load_construct")
{
    test_memory_load_construct<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_map")
{
  test_map<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_memory_cycles")
{
  test_memory_cycles<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_memory")
{
  test_memory<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_multimap")
{
  test_multimap<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_multiset")
{
  test_multiset<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_pair")
{
  test_pair<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_pod")
{
  test_pod<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_polymorphic")
{
  test_polymorphic<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_priority_queue")
{
  test_priority_queue<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_queue")
{
  test_queue<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_set")
{
  test_set<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_stack")
{
  test_stack<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_structs_minimal")
{
  test_structs_minimal<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_structs_specialized")
{
  test_structs_specialized<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_structs")
{
  test_structs<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_tuple")
{
  test_tuple<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_unordered_loads")
{
  test_unordered_loads<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_unordered_map")
{
  test_unordered_map<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_unordered_multimap")
{
  test_unordered_multimap<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_unordered_multiset")
{
  test_unordered_multiset<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_unordered_set")
{
  test_unordered_set<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_user_data_adapters")
{
  test_user_data_adapters<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_valarray")
{
  test_valarray<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_vector")
{
  test_vector<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_CASE("yaml_versioning")
{
  test_versioning<cereal::YAMLInputArchive, cereal::YAMLOutputArchive>();
}

TEST_SUITE_END();
