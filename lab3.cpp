#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argx, char *argz[]){

	bool gfn_key_v = false;
    bool gfn_key_h = false;
    bool gfn_key_R = false;
	bool gfn_key_u = false;
	bool gfn_key_H = false;

	const char* short_options = "vhu::RH::";

	const struct option full_op[] = {
        {"version",no_argument,NULL,'v'},
		{"help",no_argument,NULL,'h'},
        {"user",no_argument,NULL,'u'},
        {"refresh",optional_argument,NULL,'R'},
        {"host",optional_argument,NULL,'H'},
	};

	int res;
	int index = -1;

	while ((res=getopt_long(argx,argz,short_options,
		full_op,&index))!=-1){

		switch(res){
			case 'v': {
				if (!gfn_key_v)
					printf("flag_result: Version\n");
				gfn_key_v = true;
				break;
			};
            case 'h': {
				if (!gfn_key_h)
					printf("flag_result: Help\n");
				gfn_key_h = true;
				break;
			};
            case 'u': {
				if (!gfn_key_u)
					printf("flag_result: User\n");
				gfn_key_u = true;
				break;
			};
			case 'R': {
				if (!gfn_key_R)
					if (index > 0)
						if (optarg != NULL)
							printf("flag_result: Refresh storage, Refresh status: %s\n", optarg);
						else
						printf("flag_result of set: Nothing to reload\n");
					else
						printf("flag_result of set: Nothing to reload\n");
				gfn_key_R = true;
				break;
			};
			case 'H': {
				if (!gfn_key_H)
					if (optarg != NULL)
						printf("flag_result Hosting... Host: %s\n", optarg);
					else
						printf("flag_result Hosting not found: \n");
				gfn_key_H = true;
				break;
			};
		};
		index = -1;
	};
	return 0;
};