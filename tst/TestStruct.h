
#pragma once
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "common/struct_defines.h"
#include "common/conv.h"
#define LMCP_TestStruct_SUB "mytst.tst.TestStruct"

#define LMCP_TestStruct_TYPENAME "TestStruct"

typedef struct {
lmcp_object super;
uint32_t* tstfield;
array_info tstfield_ai;

}TestStruct;void lmcp_pack_TestStruct(uint8_t* buf, TestStruct* i);
void lmcp_unpack_TestStruct(uint8_t* buf, TestStruct** outp);
uint32_t lmcp_packsize_TestStruct (TestStruct* i);
void lmcp_init_TestStruct (TestStruct* i);