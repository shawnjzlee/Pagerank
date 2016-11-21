import sys
import sys

def compare(file1, file2):
    total_difference = 0
    with open(file1) as f1, open(file2) as f2:
        for line1, line2 in zip(f1, f2):
            line1_arr = line1.split()
            line2_arr = line2.split()
            
            # if not (isinstance(line1_arr[1], float) or isinstance(line2_arr[1], float)):
            if (float(line1_arr[1]) - float(line2_arr[1])) < 1.0:
                continue
            else:
                total_difference += 1
    print total_difference

if __name__ == "__main__":
  file1 = sys.argv[1]
  file2 = sys.argv[2]
  compare(file1, file2)