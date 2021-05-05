#include <err.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[])
{
	TEEC_Result res;
	TEEC_Context ctx;
	TEEC_Session sess;
	TEEC_Operation op;
	TEEC_UUID uuid = TA_TEEencrypt_UUID;
	uint32_t err_origin;

	char enc_cmd[] = "-e";
	char dec_cmd[] = "-d";
	char rsa_cmd[] = "RSA";
	char csr_cmd[] = "Caesar";
	char text[100]={0,};
	char ciphertext[100]={0,};
	char keytext[100]={0,};
	char clear[86];
	char ciph[1024/8];
	

	res = TEEC_InitializeContext(NULL, &ctx);
	if (res != TEEC_SUCCESS)
		errx(1, "TEEc failed", res);
	res = TEEC_OpenSession(&ctx, &sess, &uuid,
			       TEEC_LOGIN_PUBLIC, NULL, NULL, &err_origin);
	if (res != TEEC_SUCCESS)
		errx(1, "TEEC opensession fail",			res, err_origin);
	
	memset(&op, 0, sizeof(op));
				
	op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_OUTPUT,
					 TEEC_VALUE_INOUT,	
					 TEEC_MEMREF_TEMP_INPUT,
					 TEEC_MEMREF_TEMP_OUTPUT);
	op.params[0].tmpref.buffer = text;
	op.params[0].tmpref.size = MAX_LEN;

	if(argc == 0 || argc > 5){
		printf("Invalid execution statement.\n");
		TEEC_CloseSession(&sess);
		TEEC_FinalizeContext(&ctx);
		return 1;
	}

	
	if(!strcmp(enc_cmd, argv[1])){
	
		TEEC_Result ret;
		
		FILE* fs;
		fs = fopen(argv[2], "r");
		fread(text, sizeof(text), 1, fs);
		fclose(fs);
		printf("======text=======\n%s\n",text);
		memcpy(op.params[0].tmpref.buffer, text, MAX_LEN);
		char *cipher = NULL;

		

	return 0;
}
