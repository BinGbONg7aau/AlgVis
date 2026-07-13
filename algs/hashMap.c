#include "hashMap.h"
#include "../helperFunctions.h"

#define INITIAL_CAPACITY 8u

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashMap {
    Entry **table; //An array of bucket pointers
    unsigned int capacity;
    unsigned int size;
} HashMap;

static Entry *createEntry(int key, int value);
static void initMap(HashMap *map);
static void insert(HashMap *map, int key, int value);
static void resizeMap(HashMap *map, unsigned int newCapacity);
static void printMap(const HashMap *map);
static void freeMap(HashMap *map);
static unsigned int hashMultiplicative(int key, unsigned int capacity);
static void searchValue(const HashMap *map, int key);

void hashMap() {
    HashMap map;
    int length = -1;
    int *keys;

    initMap(&map);

    printf("HASH MAP DEMO\n");
    printf("Using a simple chaining hash table\n\n");

    promptArrayLength(&length);
    keys = generateArray(length);
    populateArrayRandom(keys, length);

    for (int i = 0; i < length; i++) {
        unsigned int index = hashMultiplicative(keys[i], map.capacity);
        printf("Step %d: key=%d, value=%d -> hash=%u, bucket=%u\n",
               i + 1, keys[i], keys[i] * 2, index, index);
        insert(&map, keys[i], keys[i] * 2);
        printf("Inserted key %d with value %d\n", keys[i], keys[i] * 2);
        printMap(&map);
    }

    printf("\nFinal hash map:\n");
    printMap(&map);

    printf("Enter a key to search for: ");
    int searchKey = 0;
    scanf(" %d", &searchKey);
    searchValue(&map, searchKey);

    freeMap(&map);
}

static Entry *createEntry(int key, int value) {
    Entry *entry = malloc(sizeof(Entry));
    if (entry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

static void initMap(HashMap *map) {
    map->table = calloc(INITIAL_CAPACITY, sizeof(Entry *));
    if (map->table == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    map->capacity = INITIAL_CAPACITY;
    map->size = 0;
}

static unsigned int hashMultiplicative(int key, unsigned int capacity) {
    return ((unsigned int)key * 2654435761u) % capacity;
}

static void resizeMap(HashMap *map, unsigned int newCapacity) {
    Entry **newTable = calloc(newCapacity, sizeof(Entry *));
    if (newTable == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < map->capacity; i++) {
        Entry *current = map->table[i];

        while (current != NULL) {
            Entry *next = current->next;
            unsigned int newIndex = hashMultiplicative(current->key, newCapacity);

            current->next = newTable[newIndex];
            newTable[newIndex] = current;
            current = next;
        }
    }

    free(map->table);
    map->table = newTable;
    map->capacity = newCapacity;
}

static void insert(HashMap *map, int key, int value) {
    if (map->size * 4u >= map->capacity * 3u) {
        resizeMap(map, map->capacity * 2u);
    }

    unsigned int index = hashMultiplicative(key, map->capacity);
    Entry *entry = createEntry(key, value);

    entry->next = map->table[index];
    map->table[index] = entry;
    map->size++;
}

static void searchValue(const HashMap *map, int key) {
    unsigned int index = hashMultiplicative(key, map->capacity);
    Entry *current = map->table[index];
    int step = 1;

    printf("\nSEARCH VISUALIZATION\n");
    printf("Target key: %d\n", key);
    printf("Computed bucket: %u\n", index);
    printf("Bucket %u contents:\n", index);

    while (current != NULL) {
        printf("  Step %d: [%d:%d]", step, current->key, current->value);
        if (current->key == key) {
            printf(" <- match\n");
            printf("Found key %d with value %d\n", current->key, current->value);
            return;
        }
        printf(" -> ");
        current = current->next;
        step++;
    }

    printf("  Step %d: NULL\n", step);
    printf("Key %d was not found\n", key);
}

static void printMap(const HashMap *map) {
    printf("Hash table:\n");

    for (unsigned int i = 0; i < map->capacity; i++) {
        printf("Bucket %u: ", i);

        Entry *current = map->table[i];
        if (current == NULL) {
            printf("EMPTY\n");
            continue;
        }

        while (current != NULL) {
            printf("[%d:%d]", current->key, current->value);
            if (current->next != NULL) {
                printf(" -> ");
            }
            current = current->next;
        }

        printf("\n");
    }

    printf("\n");
}

static void freeMap(HashMap *map) {
    for (unsigned int i = 0; i < map->capacity; i++) {
        Entry *current = map->table[i];

        while (current != NULL) {
            Entry *next = current->next;
            free(current);
            current = next;
        }
    }

    free(map->table);
    map->table = NULL;
    map->capacity = 0;
    map->size = 0;
}
