#include <iostream>

using namespace std;

void increase_temp(int* temp, int amount){
	if (temp != nullptr){
		*temp += amount;
	}
}

void display_temp(const int* temp) {
	if (temp != nullptr){
		cout << "Current Temperature: " << *temp << " C\n";
	} else {
		cout << "No temperature sensor available!\n";
	}
}


int main()
{
	cout << "MEMORY EXPLORER\n";
	cout <<"----------------------\n\n";

	int cpuTemp = 62;
	int gpuTemp = 55;	//Celsius
	double ramUsage = 7.5; // GB
	char systemStatus = 'N';  // N = Normal

	cout << "PART 1: HARDWARE MEMORY ADDRESSES\n";

	cout << "CPU TEMP: " << cpuTemp << " C\n";
	cout << "CPU Address: " << &cpuTemp << endl;
	cout << "CPU Size:  " << sizeof(cpuTemp) << " bytes\n\n";

	cout << "GPU TEMP:  " << gpuTemp << " C\n";
        cout << "GPU Address: " << &gpuTemp << endl;
        cout << "GPU Size:  " << sizeof(gpuTemp) << " bytes\n\n";

	cout << "RAM Usage: " << ramUsage << "C\n";
	cout << "RAM Address " << &ramUsage << endl;
	cout << "RAM Size: " << sizeof(ramUsage) << " bytes\n\n";	

	cout << "System Status: " << systemStatus << " C\n ";
	cout << "Status Address: " << static_cast<const void*>(&systemStatus) << endl;
	cout << "Status Sizer: " << sizeof(systemStatus) << " bytes\n\n";

	cout << "PART 2: HARDWARE POINTERS\n\n";
	
	int* cpuPtr = &cpuTemp;
	double* ramPtr = &ramUsage;
	
	cout << "CPU Temp: " << cpuTemp << endl;
	cout << "CPU Address: " << &cpuTemp << endl;
	cout << "Pointer stores: " << cpuPtr << endl;
	cout << "Pointer address: " << &cpuPtr << endl;

	cout << endl;

	cout << "RAM Usage: " << ramUsage << endl;
        cout << "RAM Address: " << &ramUsage << endl;
        cout << "Pointer stores: " << ramPtr << endl;
        cout << "Pointer address: " << &ramPtr << endl;

	cout << "\nPART 3: DEREFERENCING POINTERS\n";
	
	cout << "CPU Temp: " << cpuTemp << endl;
	cout << "CPU Pointer Address: " << cpuPtr << endl;
	cout << "CPU Dereferenced Value: " << *cpuPtr << endl;

	cout << endl;

	cout << "RAM Usage: " << ramUsage << endl;
	cout << "RAM Dereferenced Value " << *ramPtr << endl;

	cout << "\nPART 4: UPDATING HARDWARE READINGS\n";

	cout << "Original CPU Temp: " << cpuTemp << endl;
	
	*cpuPtr = 78;
	
	cout << "Updated CPU Temp: " << cpuTemp << endl;
	cout << "value through the pointer: " << *cpuPtr << endl;

	*ramPtr += 1.5;
	
	cout << "\nUpdated RAM Usage: " << ramUsage << endl;

	cout << "\nPART 5: SENSOR AVAILABILITY (nullptr)\n";

	int* sensorPtr = nullptr;

	if(sensorPtr == nullptr){
		cout << "No temp sensor selected\n";
	}

	sensorPtr = &cpuTemp;

	if (sensorPtr != nullptr){
		cout << "CPU sensor connected.\nCurrent reading:" << *sensorPtr << endl;
	}

	cout << "\nPART 6: SWITCHING SENSORS\n\n";
	
	cout << "Active sensor: CPU, Reading: " << *sensorPtr << endl;
	

	// actual switching part
	sensorPtr = &gpuTemp;

	cout << "Active sensor: GPU, Reading: " << *sensorPtr << endl;

	*sensorPtr = 65;

	cout << "Updated GPU temp: " << gpuTemp << endl;
	cout << "CPU temp: " << cpuTemp << endl;

	cout << "\nPART 7: POINTERS VS REFERENCES\n\n";

	// create reference to the cpu temp
	int& cpuRef = cpuTemp;

	// create a pint to the cpu temp
	int* currentPtr = &cpuTemp;

	cout << "CPU Temp: " << cpuTemp << endl;
	cout << "Reference Value: " << cpuRef << endl;
	cout << "Pointer Value: " << *currentPtr << endl;

	cpuRef = 82;

	cout << "After increasing through reference, CPU Temp: " << cpuTemp << endl;

	*currentPtr = 85;

	cout << "After increasing through pointer, CU Temp: " << cpuTemp << endl;

	cout << "\nPART 8: POINTER FUNCTION PARAMETERS\n\n";

	cout << "Before CPU update: ";
	 display_temp(&cpuTemp);
	
	//simulate cpu rising by 5deg
	increase_temp(&cpuTemp, 5);

	cout << "After CPU update: ";
	display_temp(&cpuTemp);

	//simulate gpu rising by 5deg
        increase_temp(&cpuTemp, 5);

        cout << "After GPU update: ";
	display_temp(&gpuTemp);

	// demo a null argument
	cout << "Unavilable sensor: ";
	display_temp(nullptr);

	cout << "\nPART 9: POINTER FUNCTION PARAMETERS\n\n";
	
	// simulated readings collected over time
	int temperature[5] = {62, 65, 68, 72, 75};
	
	// pointer to first element (default)
	int* tempHPtr = temperature;

	cout << "Temperature readings:\n";

	for (int i = 0; i < 5; i++){
		cout << "Reading " <<  i + 1 <<": " << temperature[i] << endl;
	} 
	
	cout << "Memory Addresses:\n";

	for (int i = 0; i < 5; i++){ 
                 cout << "Reading " <<  i + 1 << "Address: " << &temperature[i] << endl;
         }

	cout << "\nPointer Arithmetic\n";
	
	cout << "First Reading: " << *tempHPtr << endl;
	cout << "Second Reading: " << *(tempHPtr + 1) << endl; 
	// continue next class period
	return 0;

}	
