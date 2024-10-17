#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Region {
public:
    int Id, Population, RiskFactor, VaccinesReceived;
    string Name;

    Region(int id, string name, int population, int riskFactor)
        : Id(id), Name(name), Population(population), RiskFactor(riskFactor), VaccinesReceived(0) {}
};

class VaccineDistribution {
private:
    vector<Region> regions;
    int totalVaccines;

public:
    void AddRegion(int id, string name, int population, int riskFactor) {
        regions.push_back(Region(id, name, population, riskFactor));
    }

    void UpdateVaccineSupply(int vaccines) {
        totalVaccines = vaccines;
    }

    void DistributeVaccines() {
        sort(regions.begin(), regions.end(), [](Region& r1, Region& r2) {
            if (r1.RiskFactor == r2.RiskFactor)
                return r1.Population > r2.Population; 
            return r1.RiskFactor > r2.RiskFactor;  
        });

        for (Region& region : regions) {
            if (totalVaccines <= 0)
                break;

            int vaccinesToGive = min(totalVaccines, region.Population);
            region.VaccinesReceived = vaccinesToGive;
            totalVaccines -= vaccinesToGive;
        }
    }

    void GenerateReport() {
        int totalVaccinated = 0;
        int highRiskVaccinated = 0, highRiskPop = 0;

        for (const Region& region : regions) {
            cout << region.Name << " received " << region.VaccinesReceived << " vaccines.\n";
            totalVaccinated += region.VaccinesReceived;
            if (region.RiskFactor >= 50) {
                highRiskVaccinated += region.VaccinesReceived;
                highRiskPop += region.Population;
            }
        }

        cout << "Remaining vaccines: " << totalVaccines << "\n";
        cout << "Total vaccinated: " << totalVaccinated << "\n";

        double highRiskCoverage = (highRiskPop > 0) ? (double)highRiskVaccinated / highRiskPop * 100 : 0;
        cout << "High-risk coverage: " << highRiskCoverage << "%\n";
    }
};

int main() {
    VaccineDistribution dist;
    
    dist.AddRegion(1, "Rajkot", 1400000, 85);
    dist.AddRegion(2, "Ahmedabad", 5500000, 75);
    dist.AddRegion(3, "Vadodara", 2100000, 65);

    dist.UpdateVaccineSupply(4000000);

    dist.DistributeVaccines();

    dist.GenerateReport();

    return 0;
}
