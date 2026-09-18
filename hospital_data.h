#ifndef HOSPITAL_DATA_H_INCLUDED
#define HOSPITAL_DATA_H_INCLUDED

void initialize_beds();
void display_specialties();
void diaplay_wards();

float get_specialty_fee(int id);
int get_specialty_time(int id);
int get specialty_cap(int id);
float get_ward_rate(int id);

#endif // HOSPITAL_DATA_H_INCLUDED
