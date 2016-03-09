

#include <stdio.h>
#include <string.h>
#include "track_input.h"

int segments = -1;
int tabs = -1;

int main(int argc, char** argv){
	read_input();


	return 0;
}

int read_input(){
	char const* const filename ="track.tsv";
	FILE* file = fopen(filename,"r");
	char line [256];
	int current_line = 0;

	while(fgets(line, sizeof(line),file)){
		if(current_line == 0){
			tabs = get_num_tabs(line);
		}
		if(current_line == 3){
			char** line_in_tabs;
			split_on_tab(line, line_in_tabs);

			for(int i = 0;i< sizeof(**line_in_tabs)/sizeof(*line_in_tabs[0]);i++){
				//printf("split_on_tab: %c\n", line_in_tabs[0]);
			}

		}

		
		current_line++;
	}
	printf("tabs: %i\n", tabs);

	fclose(file);

	return 0;
}





int split_on_tab(char* line, char** line_in_tabs){
	char *segment;
	segment = strtok(line, "\t");
	int counter = 0;
	while( segment != NULL){
		printf("segment: %s\n", segment);
		strncpy(line_in_tabs[counter], segment,strlen(segment));

		segment = strtok(NULL,"\t");
		counter++;

	}

	return 0;

}



int get_num_tabs(char* line){
	size_t string_size = strlen(line);
	int tabs_found = 0;
	for(int i = 0;i<string_size;i++){
		if(line[i] == '\t'){
			tabs_found++;
		}
	}
	//printf("%i", string_size);
	return tabs_found;
}
