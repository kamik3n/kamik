#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "../src/Converter.h"
struct STestCase { std::string name; std::function<int()> func; };
class CFixture {
public:
 void AddTest(std::string name,std::function<int()> test){tests.push_back({std::move(name),std::move(test)});}
 int Run(){for(const auto& t:tests){try{if(t.func()==0){++passed;std::cout<<"[PASS] "<<t.name<<'\n';}else{++failed;std::cout<<"[FAIL] "<<t.name<<'\n';}}catch(const std::exception& e){++failed;std::cout<<"[FAIL] "<<t.name<<": "<<e.what()<<'\n';}}std::cout<<"Results: "<<passed<<" passed, "<<failed<<" failed\n";return failed;}
private: std::vector<STestCase> tests; int passed=0,failed=0;
};
int TestNegativeInput(){try{NConverter::Convert(-1,NConverter::EConversionType::MillimeterToMeter);}catch(const std::invalid_argument&){return 0;}return 1;}
int TestUnsupported(){try{NConverter::Convert(1,NConverter::EConversionType::UnsupportedConversion);}catch(const std::invalid_argument&){return 0;}return 1;}
int TestMM(){return NConverter::Convert(0,NConverter::EConversionType::MillimeterToMeter)==0&&NConverter::Convert(1500,NConverter::EConversionType::MillimeterToMeter)==1.5?0:1;}
int TestCM(){return NConverter::Convert(0,NConverter::EConversionType::CentimeterToMeter)==0&&NConverter::Convert(150,NConverter::EConversionType::CentimeterToMeter)==1.5?0:1;}
int TestDM(){return NConverter::Convert(0,NConverter::EConversionType::DecimeterToMeter)==0&&NConverter::Convert(15,NConverter::EConversionType::DecimeterToMeter)==1.5?0:1;}
int TestKM(){return NConverter::Convert(0,NConverter::EConversionType::MeterToKilometer)==0&&NConverter::Convert(1500,NConverter::EConversionType::MeterToKilometer)==1.5?0:1;}
int main(){CFixture f;f.AddTest("TestNegativeInput",TestNegativeInput);f.AddTest("TestUnsupportedConversionType",TestUnsupported);f.AddTest("TestMillimeterToMeter",TestMM);f.AddTest("TestCentimeterToMeter",TestCM);f.AddTest("TestDecimeterToMeter",TestDM);f.AddTest("TestMeterToKilometer",TestKM);return f.Run();}
