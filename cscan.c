#include <stdio.h>
#include <stdlib.h>

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
    
    // Sorting the requests in ascending order
    for (int i = 0; i < total_requests - 1; i++) {
        for (int j = i + 1; j < total_requests; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
    
    int current_index = 0;
    int total_distance = 0;
    
    // Finding the index of current position in the sorted requests
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
    if (current_index != 0) {
        printf("%d ", disk_size - 1);
        total_distance += abs(disk_size - 1 - current_pos);
        current_pos = disk_size - 1;
        
        for (int i = current_index - 1; i >= 0; i--) {
            printf("%d ", requests[i]);
            total_distance += abs(requests[i] - current_pos);
            current_pos = requests[i];
        }
    }
    
    printf("\nTotal Head Movement: %d\n", total_distance);
    
    return 0;
}