#pragma once

#define private public

#include <fuzzcover/fuzzcover.hpp>
#include "iban.hpp"

class iban_fuzz : public fuzzcover::fuzzcover_interface<std::string>
{
  public:
    test_input_t value_from_bytes(const std::uint8_t* data, std::size_t size) override
    {
        FuzzedDataProvider data_provider(data, size);
        return data_provider.ConsumeRemainingBytesAsString();
    }

    void test_function(const test_input_t& value) override
    {
        is_valid_iban(value);
    }
};
