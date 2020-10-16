#include "functions.h" //this .h already includes: iostream, cmath
			//vector, climits

					   //this .h IS already useing std namespace

int main(){

	vector<float> v{1,5,7,2,1,8,3,1};
	mad::print(v);
	
	float dev_avg = mad::sum_deviation_from_average(v);
	float scarto_ass_avg = mad::abs_deviation_from_average(v);
	float scarto_ass_med = mad::abs_deviation_from_median(v);
	float var = mad::variance(v);
	float dev = mad::standard_deviation(v);
	float avg = mad::average(v);
	float med = mad::median(v);
	float skew = mad::skewness(v);
	float kurt = mad::kurtosis(v);

	cout << avg << " " << med << endl;

	cout << dev_avg << " ";
	cout << scarto_ass_avg << " ";
	cout << scarto_ass_med << " ";
	cout << var << " ";
	cout << dev << " ";
	cout << skew << " ";
	cout << kurt << " ";
	cout << endl;

	vector<float> v2{3,6,7,4,4,2,7,3,2,6,2,9,5,5,6};
	mad::sort(v2);
	mad::print(v2);
	float p30 = mad::percentile(v2, 30);
	float p25 = mad::percentile(v2, 25);
	float p50 = mad::percentile(v2, 50);
	float p75 = mad::percentile(v2, 75);
	float p10 = mad::percentile(v2, 10);
	float p90 = mad::percentile(v2, 90);
	float p20 = mad::percentile(v2, 20);

	cout << p30 << " " << p25 << " " << p50 << " " << p75 << " " << p10 << " " << p90 << " " << p20 << endl;

	vector<float> v3{1,3,5,7,9};
	vector<float> v4{2,4,4,5,10};
	float pers = mad::pearson(v3,v4);
	cout << "pers=" << pers << endl;

	float expected = mad::expected_value(v3,v4,15);
	cout << "exptected value = " << expected;
}
