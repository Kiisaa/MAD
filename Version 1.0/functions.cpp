#include "functions.h"

void mad::print(const vector<float> &v){
	
	int len = v.size();
	
	cout << "{";
	for(int i=0; i<len; i++){
		if	   (i != len-1) cout << v[i] << ",";
		else if(i == len-1) cout << v[i] << "}\n";
	}
}

float mad::round(float n){ 
	
	float rounded = floor((n * 100) + .5) / 100;
	return rounded;
}

void mad::swap(vector<float> &v, float i, float j){
	
	float tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void mad::sort(vector<float> &v){
	
	int len = v.size();
	
	for(int i=0; i<len; i++){
		float min = INT_MAX;
		int pos = 0;
		
		for(int j=i; j<len; j++){
			
			if(v[j] < min){
				min = v[j];
				pos = j;
			}
		}
		swap(v, i, pos);
	}
}

float mad::average(const vector<float>& v){
	
	int len = v.size();
	float avg = 0.f;
	
	for(int i=0; i<len; i++)
		avg += v[i];
		
	avg /= len;
	return mad::round(avg);
}

float mad::median(vector<float> v){

	int len = v.size();
	mad::sort(v);

	if(len%2 == 0)	return mad::round(( (v[len/2]+v[(len/2)-1]) / 2));
	else			return mad::round(v[len/2]);
}

vector<float> mad::mode(const vector<float>& v){

	vector<float> modes;
	int len = v.size();
	if(len == 0) return modes;

	vector<float> v_unique;
	for (int i = 0; i < len; i++){
		bool flag = true;
		for (int j = 0; j < v_unique.size(); j++){
			if(v[i] == v_unique[j]){
				flag = false;
				break;
			}
		}
		if(flag) v_unique.push_back(v[i]);
	}
	
	vector<float> v_count;
	for (int i = 0; i < v_unique.size(); i++)
		v_count.push_back(0);

	for (int i = 0; i < v_unique.size(); i++)
		for (int j = 0; j < len; j++)
			if(v_unique[i] == v[j])
				v_count[i]++;
	

	float max = INT_MIN;
	for (int i = 0; i < v_count.size(); i++)
		if(v_count[i] > max)
			max = v_count[i];

	for (int i = 0; i < v_count.size(); i++)
		if(v_count[i] == max)
			modes.push_back(v_unique[i]);

	return modes;	
}

float mad::sum_deviation_from_average(const vector<float>& v){
	
	float avg = mad::average(v);
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum+=v[i]-avg;
	return mad::round(sum);
}

float mad::abs_deviation_from_median(const vector<float>& v){

	float med = mad::median(v);
	float sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum+=abs(v[i]-med);
	return mad::round(sum/v.size());
}

float mad::abs_deviation_from_average(const vector<float>& v){
	
	float avg = mad::average(v);
	float sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum+=abs(v[i]-avg);
	return mad::round(sum/v.size());
}

float mad::variance(const vector<float>& v){
	
	float avg = mad::average(v);
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum+=v[i]*v[i];
	
	float var = sum/v.size() - (avg*avg);
	return mad::round(var);
}

float mad::standard_deviation(const vector<float>& v){

	float var = mad::variance(v);
	return mad::round(sqrt(var));
}

float mad::skewness(const vector<float>& v){

	float dev_std = mad::standard_deviation(v);
	float avg = mad::average(v);
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum+=pow((v[i]-avg), 3);
	
	float var = sum/(v.size()*(pow(dev_std,3)));
	return mad::round(var);
}

float mad::kurtosis(const vector<float>& v){

	float dev_std = mad::standard_deviation(v);
	float avg = mad::average(v);
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum+=pow((v[i]-avg), 4);
	
	float var = sum/(v.size()*(pow(dev_std,4)));
	return mad::round(var);
}

bool mad::is_digit(float n){
	
	for (int i = 0; i < 10; i++)
		if(n==i)
			return true;

	return false;
}

float mad::percentile(vector<float>& v, float q){

	q/=100;
	int len = v.size();
	float prod = q*len;
	mad::sort(v);

	if(mad::is_digit(prod))	return ((v[prod-1] + v[prod]) / 2);
	else					return v[prod];
}

float mad::covariance(const vector<float>& v1, const vector<float>& v2){
	
	int len = v1.size();
	if(v2.size() != len) {cout << "different length not allowed!\n"; return 0;}
	float avg1 = mad::average(v1);
	float avg2 = mad::average(v2);
	float sum = 0;
	for (int i = 0; i < len; i++)
		sum+= v1[i]*v2[i];

	float cov = sum/len;
	cov -= avg1*avg2;
	return mad::round(cov);	

}

float mad::pearson(const vector<float>& v1, const vector<float>& v2){

	float cov = mad::covariance(v1,v2);
	float dev1 = mad::standard_deviation(v1);
	float dev2 = mad::standard_deviation(v2);
	float pers = cov / (dev1 * dev2);
	return mad::round(pers);
}

vector<float> mad::sline(const vector<float>& v1,const vector<float>& v2){
	
	vector<float>line;
	float avg1 = mad::average(v1);
	float avg2 = mad::average(v2);
	float cov = mad::covariance(v1,v2);
	float var1 = mad::variance(v1);
	float a = mad::round(cov / var1);
	float b = mad::round(avg2 - (avg1*a));
	line.push_back(a);
	line.push_back(b);
	cout << "linear regression from straigth line:\n";
	cout << "y = " << line[0] << "x + " << line[1] << endl;
	return line;

}

float mad::expected_value(const vector<float>& v1, const vector<float>& v2, float x){

	vector<float> reg = mad::sline(v1,v2);
	float y = mad::round((reg[0]*x) + reg[1]);
	return y; 
}
