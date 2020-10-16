# CHANGELOG 1.0

uploaded 16-10-20

avaiable functions:


    void sort(vector<float>&);
        
        Implementation of selection sort algorithm to sort a vector of float (it modifies the original vector ).


    void print(const vector<float>&);
        
        Just a simple function to show a vector like "{x1, x2, x3...}".
        

    void swap(vector<float>&, float, float);
    
        Just a simple function to swap two float elements of a vector (it modifies the original vector )


    float round(float);
    
        This function returns a copy of any float with only 2 digits after the decimal point, example: 1.567 -> 1.56


    float average(const vector<float>&);
    
        Simple function to calculate the average of a float vector.


    float median(vector<float>);
    
        Simple function to calculate the average of a float vector of course, sorting a copy of the original vector.


    float sum_deviation_from_average(const vector<float>&);
    
        Simple function to calculate the sum of deviations from the average in a vector of float.


    float abs_deviation_from_average(const vector<float>&);

        Simple function to calculate the absolute sum of deviations from the average in a vector of float.
        

    float abs_deviation_from_median(const vector<float>&);

        Simple function to calculate the absolute sum of deviations from the median in a vector of float.
        

    float variance(const vector<float>&);
        
        Simple function to calculate the variance of a vector of float.
        

    float standard_deviation(const vector<float>&);//sqrt(1/n(x1² + x2²...)-(xa²))

        Simple function to calculate the standard deviation of a vector of float using the variance function.
        

    float skewness(const vector<float>&);

        Simple function to calculate skewness index.
        

    float kurtosis(const vector<float>&);

        Simple function to calculate kurtosis index.
        

    float pearson(const vector<float>&, const vector<float>&);

        Simple function to calculate Pearson index.
        

    float percentile(vector<float>&, float);//return qth percentile of a vector

        Simple function to calculate any percentile in a vector of float, of course, sorting a copy of the given vector.
        

    float covariance(const vector<float>&, const vector<float>&);
        
        Simple function to calculate the covariance between two given float vectors.


    float expected_value(const vector<float>&, const vector<float>&, float);

        Simple function to calculate the expected value using linear regression method calculated with sline.
        

    vector<float> mode(const vector<float>&);

        Simple function to calculate modes of a vector of float and store them in a new vector.
        

    vector<float> sline(const vector<float>&,const vector<float>&);//creates a vector cointaing a,b (linear regression straigth line)
        
        Simple function to create a vector containing A and B, which are the coefficients for the straigth line to calculate linear regression.


    bool is_digit(float);//return true if parameter is a single digit
        
        Stupid easy function to see if a number is a digit between 0 and 9
