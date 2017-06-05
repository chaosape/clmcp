
#define LMCP_TestStruct_SUB "mytst.tst.TestStruct"

#define LMCP_TestStruct_TYPENAME "TestStruct"

typedef struct {
otherstruct super;
uint32_t* tstfield;
array_info tstfield_ai;

// Units: hi 
char* ldj;
array_info ldj_ai;

}TestStruct;typedef enum {
hi2,
hi = 10,
} myen;
uint32_t lmcp_TestStruct_packsize (TestStruct* i) { 
uint32_t out = 0;
out += lmcp_otherstruct_packsize(i->super);
out += 2;
for (uint32_t index = 0; index < i->tstfield_ai.length; index++) { 
out += sizeof(uint32_t);
} 
out += 2;
for (uint32_t index = 0; index < i->ldj_ai.length; index++) { 
out += sizeof(char);
} 
return out;} 

void lmcp_pack_TestStruct(uint8_t* buf, TestStruct* i) { 
uint8_t* outb = buf;
lmcp_pack_otherstruct(outb, i->super);
lmcp_pack_uint16_t(outb, i->tstfield_ai.length); outb += 2; 
for (uint32_t index = 0; index < i->tstfield_ai.length; index++) {
if (i->tstfield[index]==NULL) { 
lmcp_pack_uint8_t(outb, 0); outb += 1;
} else { 
lmcp_pack_uint8_t(outb, 1); outb += 1; 
memcpy(outb, "MYTEST  ", 8); outb += 8; 
lmcp_pack_uint32_t(outb, 1); outb += 4; 
lmcp_pack_uint16_t(outb, 1); outb += 2; 
lmcp_pack_uint32_t(outb, i->tstfield[index]); outb += lmcp_uint32_t_packsize(i->tstfield[index]);
}
lmcp_pack_uint16_t(outb, i->ldj_ai.length); outb += 2; 
for (uint32_t index = 0; index < i->ldj_ai.length; index++) {
if (i->ldj[index]==NULL) { 
lmcp_pack_uint8_t(outb, 0); outb += 1;
} else { 
lmcp_pack_uint8_t(outb, 1); outb += 1; 
memcpy(outb, "MYTEST  ", 8); outb += 8; 
lmcp_pack_uint32_t(outb, 1); outb += 4; 
lmcp_pack_uint16_t(outb, 1); outb += 2; 
lmcp_pack_char(outb, i->ldj[index]); outb += lmcp_char_packsize(i->ldj[index]);
}
}

void lmcp_unpack_TestStruct(uint8_t* buf, TestStruct* out) { 
out = malloc(sizeof(TestStruct));
uint8_t* inb = buf; 
uint32_t tmp; 
uint8_t isnull; 
uint32_t objtype; uint32_t objseries; 
inb += lmcp_unpack_otherstruct(inb, i->super);
inb += lmcp_unpack_uint16_t(inb, &tmp);
i->tstfield = malloc(sizeof(uint32))
i->tstfield_ai.length = tmp;
for (uint32_t index = 0; index < i->tstfield_ai.length; index++) 
inb += lmcp_unpack_uint8_t(inb, &isnull); 
if (isnull == 0) { 
i->tstfield[index] = NULL; 
} else { 
i->tstfield[index] = malloc(sizeof(uint32_t));
inb += lmcp_unpack_uint32_t(inb, &objtype);  
inb += lmcp_unpack_uint16_t(inb, &objseries);  
inb += lmcp_unpack_uint32_t(inb, &(i->tstfield[index])); 
inb += lmcp_unpack_uint16_t(inb, &tmp);
i->ldj = malloc(sizeof(char))
i->ldj_ai.length = tmp;
for (uint32_t index = 0; index < i->ldj_ai.length; index++) 
inb += lmcp_unpack_uint8_t(inb, &isnull); 
if (isnull == 0) { 
i->ldj[index] = NULL; 
} else { 
i->ldj[index] = malloc(sizeof(char));
inb += lmcp_unpack_uint32_t(inb, &objtype);  
inb += lmcp_unpack_uint16_t(inb, &objseries);  
inb += lmcp_unpack_char(inb, &(i->ldj[index])); 
}

