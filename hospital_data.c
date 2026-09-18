#include <stdio.h>
#include "hospital_data.h"

const char specialties[4][30] = {"General Practice (OPD)", "Paediatrics", "Cardiology", "Neurology
const float specialty_fee[4] = {1500.00, 2500.00, 4500.00, 5000.00};
const int specialty_times[4] = {15,20,30,30};
const int specialty_cap[4] = {30,20,12,10};

const char wards[4][30] = {"General Ward", "Peadiatric Ward", "Surgical Ward", "ICU (Intensive Care Unit)"};
const float ward_rates[4] = {3000.00, 6000.00, 12000.00, 25000.00};

int bedOccupancy[4][20];

void initialize_beds() {
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j<20 ; j++) {
            bedOccupancy[i][j] = 0;
        }
    }
}

void display_specialties() {
    printf("\n--- Doctor Specialties ---\n");
    for (int i=0 ; i<4 ; i++) {
        printf("%d. %s - LKR %.2f (Cap: %d/day)\n",i+1, specialties[i], specialty_fees[i], specialty_cap[i]);
    }
}

void display_wards() {
    printf("\n--- Hospital Wards ---\n");
    for (int i=0 ; i<4 ; i++) {
        printf("%d. %s - LKR %.2f/day\n", i+1, wards[i], ward_rates[i]);
    }
}

float get_specialty_fee(int id) {
    if (id >=1 && id<=4) return specialty_fee[id-1];
    return 0.0;
}

int get_specialty_time(int id) {
    if (id>=1 && id<=4) return specialty_times[id-1];
    return 0;
}
