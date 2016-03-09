#ifndef TRACK_INPUT_FILE
#define TRACK_INPUT_FILE

int main(int argc, char** argv);

int read_input();

int split_on_tab(char* line,char** line_in_tabs);

int get_num_tabs(char* line);

#endif