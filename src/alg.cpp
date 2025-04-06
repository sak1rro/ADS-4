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
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      k++;
      int currentLeft = arr[left];
      int currentRight = arr[right];
      while (left < right && arr[left] == currentLeft) left++;
      while (left < right && arr[right] == currentRight) right--;
    }
    else if (sum < value) {
      left++;
    }
    else {
      right--;
    }
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
      if (arr[mid] == complement) {
        k++;
        break;
      }
      else if (arr[mid] < complement) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
  }
  return k;
}
