#include <iostream>
#include <cstdio>
#include "integration.c"
#include <jansson.h>

// Jansson installation:

// 	   1) get here: http://www.digip.org/jansson/releases/jansson-2.6.tar.bz2
// 	   2) unpack
// 	   3) ./configure
// 	   	  make
// 	      make check
// 	      make install

// Useful commands:
	
// 	  echo “/usr/local/lib” > /etc/ld.so.conf.d/usr_local.conf
// 	  /sbin/ldconfig

// Compilation:

// 	   g++ json.cpp -Wno-write-strings -ljansson

int main() {

	// On input (stdin):
	// ["ln sin t", "0.0", "Pi", "t", 3]
	// It should return (stdout):
	// [-2.1775291224329774, 0.00032444331199360673, "G", -16, "computation timed out"]

	char *input_text = new char [512];
	size_t n_bytes = 512;
	getline(&input_text, &n_bytes, stdin);

	// Unpacking and parsing:

	json_t *input_json;
	json_error_t error;

	input_json = json_loads(input_text, 0, &error);

	char * function, *ldomain, *udomain, *var;
	int comp_time;

	json_unpack(input_json, "[ssssi]", &function, &ldomain, &udomain, &var, &comp_time);
	
	// Evaluating:

	IntResult *result    = new IntResult;
	int *comp_error_code = new int;

	clock_t index = clock();

	integrate(ldomain, udomain, function, var[0], ABS_EPS, REL_EPS, MAX_INTERVALS, (comp_time * CLOCKS_PER_SEC), result, comp_error_code);
	
	int delayClocks = (int)(clock() - index);
	int delay = static_cast<int>(static_cast<double>(delayClocks) * 1000 / CLOCKS_PER_SEC);

	// Preparing for packing:

	char mode [1];
	mode[0] = static_cast<char>(result->mode);
	mode[1] = 0;

	char *msg = new char [128];
	strcpy(msg, error_msg(*comp_error_code));

	// Packing results:

	json_t *output_json;
	output_json = json_array();

	output_json = json_pack("[ffsisis]", static_cast<double>(result->value), static_cast<double>(result->eps), mode, *comp_error_code, msg, delay, input_text);	

	char *output_text;
	output_text = json_dumps(output_json, 0);

	puts(output_text);

	// Memory releases:

	free(output_text);
	delete[] input_text;
	delete[] msg;
	delete result;
	delete comp_error_code;

	return 0;
}