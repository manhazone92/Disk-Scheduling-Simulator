
# Disk Scheduling Simulator - Test Results

## Project Name
Disk Scheduling Simulator

## Testing Overview
This document contains the testing results of six disk scheduling algorithms. The purpose is to verify the accuracy and reliability of the simulator.

## Test Environment
- Programming Language: C++
- Standard: C++17
- Operating System: Linux / Windows
- Testing Method: Manual Testing

## 1. FCFS (First Come First Serve)

- Initial Head Position: 50
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Expected Head Movement: 642
- Actual Head Movement: To be verified
- Status: Pending

## 2. SSTF (Shortest Seek Time First)

- Initial Head Position: 50
- Request Queue: 82, 170, 43, 140, 24, 16, 190
- Expected Head Movement: 208
- Actual Head Movement: To be verified
- Status: Pending

## 3. SCAN

- Initial Head Position: 50
- Disk Range: 0-199
- Direction: Right
- Expected Head Movement: 332
- Actual Head Movement: To be verified
- Status: Pending

## 4. C-SCAN (Circular SCAN)

- Initial Head Position: 50
- Disk Range: 0-199
- Direction: Right
- Expected Head Movement: 391
- Actual Head Movement: To be verified
- Status: Pending

## 5. LOOK

- Initial Head Position: 50
- Direction: Right
- Expected Head Movement: 314
- Actual Head Movement: To be verified
- Status: Pending

## 6. C-LOOK (Circular LOOK)

- Initial Head Position: 50
- Direction: Right
- Expected Head Movement: 341
- Actual Head Movement: To be verified
- Status: Pending

## 7. Edge Case Testing

| Test Scenario | Expected Result | Status |
|---|---|---|
| Empty Request Queue | No requests to process | Pending |
| Single Request | Correct head movement | Pending |
| Same Head Position | 0 head movement | Pending |
| Invalid Input | Error message | Pending |

## Overall Testing Summary

- Total Algorithms Tested: 6
- Total Test Scenarios: 10
- Successful Tests: To be updated
- Failed Tests: To be updated

## Conclusion

The testing process helps evaluate the correctness and reliability of the Disk Scheduling Simulator. Each algorithm will be tested using different request queues and initial head positions. The actual results will be compared with the expected results to identify any errors and ensure proper functionality.

