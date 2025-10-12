    #include <iostream>
    #include <string>
    #include <vector>
    #include <numeric>      
    #include <algorithm>   

    class Employee {
    private:
        
        std::string socialNumber;
        std::string name;
        int yearsOfService;
        std::string currentPosition;
        std::vector<double> salaries;
    public:
    
        Employee() {
            socialNumber = "0"; 
            yearsOfService = 0;                  

            std::cout << "Please enter the current position for the new employee: ";
            std::getline(std::cin, currentPosition);
        }

        Employee(std::string ssn, std::string empName, int serviceYears, std::string position) {
            socialNumber = ssn;
            name = empName;
            yearsOfService = serviceYears;
            currentPosition = position;
        }

        void setSocialNumber(std::string socNum) {
            socialNumber = socNum;
        }

        void setName(std::string empName) {
            name = empName;
        }

        void setYearsOfService(int exp) {
            if (exp >= 0) {
                yearsOfService = exp;
            }
        }

        void setCurrentPosition(std::string position) {
            currentPosition = position;
        }

        void setSalary(double salary) {
        if (salary > 0) {
            salaries.push_back(salary);
        }
    }

        std::string getSocialNumber() const {
            return socialNumber;
        }

        std::string getName() const {
            return name;
        }

        int getYearsOfService() const {
            return yearsOfService;
        }

        std::string getCurrentPosition() const {
            return currentPosition;
        }

        const std::vector<double>& getSalaries() const {
            return salaries;
        }

        double calculateAverageSalary() const {
            int salaryCount = salaries.size();
            if (salaryCount == 0) {
                return 0.0;
            }
            
            double sum = std::accumulate(salaries.begin(), salaries.end(), 0.0);            
            return sum / salaryCount;
        }

        double findMinSalary() const {
            int salaryCount = sizeof(salaries);
            if (salaryCount == 0) {
                return 0.0;
            }
            return *std::min_element(salaries.begin(), salaries.end());            
        }

        void displayInfo() const {
            std::cout << "====================================" << std::endl;
            std::cout << "Employee Information:" << std::endl;
            std::cout << "  -> Name: " << name << std::endl;
            std::cout << "  -> Social Security Number: " << socialNumber << std::endl;
            std::cout << "  -> Position: " << currentPosition << std::endl;
            std::cout << "  -> Years of Service: " << yearsOfService << " years" << std::endl;
            
            std::cout << "  -> Salary History:" << std::endl;
            if (!salaries.empty()) {
                std::cout << "Salaries: ";
                for (size_t i = 0; i < salaries.size(); ++i) {
                std::cout << salaries[i] << (i == salaries.size() - 1 ? "" : ", ");
            }
            std::cout << std::endl;
                std::cout << "Average Salary: " << calculateAverageSalary() << std::endl;
                std::cout << "Minimum Salary: " << findMinSalary() << std::endl;
            } else {
                std::cout << "No salary data available." << std::endl;
            }
            std::cout << "====================================" << std::endl;
        }
    };

    int main() {
        std::cout << "--- Demonstrating Default Constructor ---" << std::endl;

        Employee employee1;
        employee1.setName("Maria Georgieva");
        employee1.setSocialNumber("9505101234");
        employee1.setYearsOfService(3);
        employee1.setSalary(2500.50);
        employee1.setSalary(2600.75);
        employee1.setSalary(2700.25);

        employee1.displayInfo();

        std::cout << "\n\n--- Demonstrating Parameterized Constructor ---" << std::endl;
        Employee employee2("8801205678", "Peter Ivanov", 10, "Team Lead");

        employee2.setSalary(3100.50);
        employee2.setSalary(1600.75);
        employee2.setSalary(2760.25);
        employee2.setSalary(3017.54);

        employee2.displayInfo();

        return 0; 
    }