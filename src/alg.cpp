// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  int left = 0;
  int right = len - 1;
  for (int i = 0; i < right; i++) {
    for (int j = right - 1; j > left; j--) {
      if (arr[j] > value)
        right--;
      if (arr[i] + arr[j] == value)
        k++;
    }
    left++;
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] >= complement) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    int f = left;
    left = i + 1;
    right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] <= complement) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    int s = right;
    if (f <= s) {
      k += s - f + 1;
    }
  }
  return k;
}
