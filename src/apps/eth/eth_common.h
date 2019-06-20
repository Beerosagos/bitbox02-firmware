// Copyright 2019 Shift Cryptosecurity AG
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _APPS_ETH_COMMON_H
#define _APPS_ETH_COMMON_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <compiler_util.h>

#include <generated/hww.pb.h>

#define APP_ETH_RECIPIENT_BYTES_LEN (20)
#define APP_ETH_ADDRESS_HEX_LEN (APP_ETH_RECIPIENT_BYTES_LEN * 2 + 1) // including null terminator

/**
 * Does limit checks the keypath, whitelisting bip44 purpose and accounts.
 * @return true if the keypath is valid, false if it is invalid.
 */
USE_RESULT bool eth_common_is_valid_keypath(
    ETHCoin coin,
    const uint32_t* keypath,
    size_t keypath_len);

/**
 * Generates a checksummed ethereum hex address from a 20 byte recipient.
 * @param[in] recipient 20 byte tail (last 20 bytes of the pubkeyhash).
 * @param[out] out will hold the address string.
 * @param[in] out_len must be at least APP_ETH_ADDRESS_HEX_LEN (includes null terminator).
 */
USE_RESULT bool eth_common_hexaddress(const uint8_t* recipient, char* out, size_t out_len);

#endif
