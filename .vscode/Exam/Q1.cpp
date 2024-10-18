#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Region {
    int Id, Population, RiskFactor, VaccinesReceived = 0;
    string Name;
    
    Region(int id, string name, int population, int riskFactor)
        : Id(id), Name(name), Population(population), RiskFactor(riskFactor) {}
};

class VaccineDistribution {
    vector<Region> regions;
    int totalVaccines;

public:
    void AddRegion(int id, string name, int population, int riskFactor) {
        regions.push_back({id, name, population, riskFactor});
    }

    void UpdateVaccineSuppliess(int vaccines) {
        totalVaccines = vaccines;
    }

    void DistributeVaccines() {
        sort(regions.begin(), regions.end(), [](Region& r1, Region& r2) {
            return (r1.RiskFactor == r2.RiskFactor) ? r1.Population > r2.Population : r1.RiskFactor > r2.RiskFactor;
        });

        for (auto& region : regions) {
            if (totalVaccines <= 0) break;
            int vaccinesToGive = min(totalVaccines, region.Population);
            region.VaccinesReceived = vaccinesToGive;
            totalVaccines -= vaccinesToGive;
        }
    }

    void GenerateReport() {
        int totalVaccinated = 0, highRiskVaccinated = 0, highRiskPop = 0;

        for (auto& region : regions) {
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
    
    dist.AddRegion(1, "Rajkot", 14000, 85);
    dist.AddRegion(2, "Ahmedabad", 55000, 75);
    dist.AddRegion(3, "Mumbai", 21000, 65);

    dist.UpdateVaccineSuppliess(40000);
    dist.DistributeVaccines();
    dist.GenerateReport();

    return 0;
}
