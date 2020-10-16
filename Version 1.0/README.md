uploaded 16-10-20

avaiable functions:


    void sort(vector<float>&);//algorithm (selection sort) to order a vector


    void print(const vector<float>&);//print vector's values

    void swap(vector<float>&, int, int);//function to swap two elements of a vector


    float round(float);//returns n rounded to two digits after decimal point


    float average(const vector<float>&);//return the average of a vector


    float median(vector<float>);//return the median of a vector


    float sum_deviation_from_average(const vector<float>&);//(x1-xa)+(x2-xa)..


    float abs_deviation_from_average(const vector<float>&);//|x1-xa|+|x2-xa|..


    float abs_deviation_from_median(const vector<float>&);//|x1-xm|+|x2-xm|..


    float variance(const vector<float>&);//1/n(x1² + x2²...)-(xa²)


    float standard_deviation(const vector<float>&);//sqrt(1/n(x1² + x2²...)-(xa²))


    float skewness(const vector<float>&);//1/n(((x1-xa³)+(x2-xa³)...)/(n*sdt_dev³))


    float kurtosis(const vector<float>&);//1/n(((x1-xa⁴)+(x2-xa⁴)...)/(n*sdt_dev⁴))


    float pearson(const vector<float>&, const vector<float>&);//return cov/(std_dev v1 * std_dev v2)


    float percentile(vector<float>&, float);//return qth percentile of a vector


    float covariance(const vector<float>&, const vector<float>&);//1/n(x1*y1 + x2*y2..) - xa*ya


    float expected_value(const vector<float>&, const vector<float>&, float);//use sline to calculate the linear regression and return the expected value at 


    vector<float> mode(const vector<float>&);//return in a vector the mode or modes of a vector


    vector<float> sline(const vector<float>&,const vector<float>&);//creates a vector cointaing a,b (linear regression straigth line)


    bool is_digit(float);//return true if parameter is a single digit
