float mean_absolute_deviation(float* data, int size) {
    float sum = 0.0f;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    float mean = sum / size;

    float sum_abs_dev = 0.0f;
    for (int i = 0; i < size; i++) {
        sum_abs_dev += fabs(data[i] - mean);
    }
    return sum_abs_dev / size;
}
