#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>

using namespace std;

class Investment {
    private:
        double m_investment;
        double m_monthlyDeposit;
        int m_annualInterest;
        int m_numYears;
    public:
        void SetInvestment(double t_investment);
        void SetMonthlyDeposit(double t_monthlyDeposit);
        void SetAnnualInterest(int t_annualInterest);
        void SetNumYears(int t_numYears);
        double GetInvestment();
        double GetMonthlyDeposit();
        int GetAnnualInterest();
        int GetNumYears();

        void GetInputs();
        double GetDouble();
        int GetInt();
        void PrintTableWithMonthly(int t_startYear);
        void PrintTableWithoutMonthly(int t_startYear);

        Investment();
        Investment(double t_investment, double t_monthlyDeposit, int t_annualInterest, int t_numYears);

};

#endif