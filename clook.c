#include <stdio.h>

int main() {
    int disk_size, current_pos, total_requests;
    
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);
    
    printf("Enter the current position of the disk head: ");
    scanf("%d", &current_pos);
    
    printf("Enter the total number of disk requests: ");
    scanf("%d", &total_requests);
    
    int requests[total_requests];
    
    printf("Enter the disk requests:\n");
    for (int i = 0; i < total_requests; i++) {
        scanf("%d", &requests[i]);
    }
    
    int current_index = 0;
    int total_distance = 0;
    
    // Finding the index of current position in the requests
    for (int i = 0; i < total_requests; i++) {
        if (requests[i] >= current_pos) {
            current_index = i;
            break;
        }
    }
    
    // Scanning towards higher cylinder numbers
    printf("Scanning Order:\n");
    for (int i = current_index; i < total_requests; i++) {
        printf("%d ", requests[i]);
        total_distance += abs(requests[i] - current_pos);
        current_pos = requests[i];
    }
    
    // Scanning towards lower cylinder numbers
    for (int i = 0; i < current_index; i++) {
        printf("%d ", requests[i]);
        total_distance += abs(requests[i] - current_pos);
        current_pos = requests[i];
    }
    
    printf("\nTotal Head Movement: %d\n", total_distance);
    
    return 0;
}
