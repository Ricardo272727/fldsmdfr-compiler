#include <stdlib.h>
#include "list.h"

enum token_type { 
    identifier = 0,
    keyword = 1,
    separator = 2,
    _operator = 3,
    literal = 4,
    comment = 5 
};

struct Token{
    enum token_type name;
    char * value;
    size_t size;
};

enum token_type get_token_type(char * token, size_t size){

}
