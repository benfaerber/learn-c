#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE (50)

typedef struct entry {
    char* key;
    int val;
} entry_t;

typedef struct hashmap {
    entry_t** entries;
    int capacity;
} hashmap_t;


int hash_key(char* key, int capacity) {
    int total = 0;
    int i, letter; 
    for (i = 0; i < strlen(key); i++) {
        total += (int)key[i]; 
    }

    return total % capacity;
}

void map_print(hashmap_t* map) {
    printf("What the flip");
    for (int i = 0; i < map->capacity; i++) {
        entry_t* entry = map->entries[i]; 
        printf("%d = (%s: %d)\n", i, entry->key, entry->val);
    }
}

hashmap_t* map_new(int capacity) {
    hashmap_t* myMap = (hashmap_t*)malloc(sizeof(hashmap_t));
    myMap->entries = malloc(capacity * sizeof(entry_t*));
    myMap->capacity = capacity; 
    return myMap;
}

void map_insert(hashmap_t* map, char* key, int val) {
    int hash = hash_key(key, map->capacity);
    printf("Inserting %s with hash (%d)\n", key, hash); 
    entry_t* new_entry = malloc(sizeof(entry_t*));
    new_entry->key = key; 
    new_entry->val = val;
    map->entries[hash] = new_entry; 
}

int map_get(hashmap_t* map, char* key) {
    int hash = hash_key(key, map->capacity);
    entry_t* found = map->entries[hash];
    return found != NULL
        ? found->val
        : -1;
}


int main() {
    hashmap_t* myMap = map_new(MAP_SIZE);
    map_insert(myMap, "reggie", 2341);
    map_insert(myMap, "tim", 123);
    map_insert(myMap, "jake", 50);
    map_insert(myMap, "jill", 60);
    map_insert(myMap, "ferriss", 12); 
    printf("Did inserts");

    map_print(myMap);

    // int outp = map_get(myMap, "ferris");
    // printf("%d", outp);


    return 0;
}
