#include "catch2/catch_all.hpp"
#include "library.h"

using namespace fmi;

TEST_CASE("dyn_arr(N) throws when allocation fails")
{
	const size_t impossible_size = std::numeric_limits<size_t>::max();
	REQUIRE_THROWS_AS(
		dynamic_array(impossible_size),
		std::bad_alloc
	);
}