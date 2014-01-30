typedef struct {
    char *name;
    int x;
    int y;
} tile_t;

tile_t* new_tile(char *name, int x, int y);

void print_tile(tile_t *cur_tile);
