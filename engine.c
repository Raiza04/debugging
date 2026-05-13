#include <stdio.h>
#include <assert.h>

#define TOTAL_ENGINES 4

void engine_temp(int engine_id) {
    int temp[TOTAL_ENGINES] = {567, 789, 987, 765};

    assert(engine_id >= 0 && engine_id < TOTAL_ENGINES);

    printf("Engine %d temperature: %d Celsius\n", engine_id, temp[engine_id]);
}

int main() {
    // Scenario A: Valid index access
    printf("--- Running Test with Valid Index ---\n");
    engine_temp(2);

    // Scenario B: Invalid index access (Triggers the crash)
    printf("\n--- Running Test with Invalid Index ---\n");
    engine_temp(5);

    return 0;
}

