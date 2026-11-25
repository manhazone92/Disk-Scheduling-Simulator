
# Disk Scheduling Simulator - Test Cases

## Project Name
Disk Scheduling Simulator

## Purpose
To test the accuracy and performance of different disk scheduling algorithms.

## Test Case 1: FCFS
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Initial Head Position: 50
- Expected Total Head Movement: 642
- Expected Result: 642

## Test Case 2: SSTF
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Initial Head Position: 50
- Expected Total Head Movement: 208
- Expected Result: 208

## Test Case 3: SCAN
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Initial Head Position: 50
- Disk Range: 0-199
- Direction: Right
- Expected Total Head Movement: 332
- Expected Result: 332

## Test Case 4: C-SCAN
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Initial Head Position: 50
- Disk Range: 0-199
- Direction: Right
- Expected Total Head Movement: 391
- Expected Result: 391

## Test Case 5: LOOK
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Initial Head Position: 50
- Direction: Right
- Expected Total Head Movement: 314
- Expected Result: 314

## Test Case 6: C-LOOK
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Initial Head Position: 50
- Direction: Right
- Expected Total Head Movement: 341
- Expected Result: 341

## Test Case 7: Empty Request Queue
- Request Queue: Empty
- Expected Result: No disk requests to process.

## Test Case 8: Single Request
- Request Queue: 100
- Initial Head Position: 50
- Expected Result: Total Head Movement = 50

## Test Case 9: Same Head Position
- Request Queue: 50
- Initial Head Position: 50
- Expected Result: Total Head Movement = 0

## Test Case 10: Invalid Input
- Request Queue: Negative or non-numeric values
- Expected Result: Display an appropriate error message.

## Conclusion
These test cases help verify the correctness of all six disk scheduling algorithms and check how the simulator handles different input conditions.

