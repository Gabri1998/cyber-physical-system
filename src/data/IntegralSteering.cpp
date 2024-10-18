#include <iostream>
#include <stdlib.h>
#include "IntegralSteering.hpp"

float integralSteering(float leftVoltage, float rightVoltage, float frontDistance, float gsrBefore)
{
    float steerOne = frontSteer(frontDistance);
    float steerTwo = sideSteer(leftVoltage, rightVoltage, gsrBefore);

    if (steerTwo == 0.0) {
        return steerOne;
    }
    else if (steerOne == 0.0) {
        return steerTwo;
    }
    else {
        return (steerTwo + steerOne) / 2;
    }
    

}

// Steering angle calculation based on distance to the front cones
float frontSteer(float frontDistance)
{
    float steerFront;
    // Group 3 (95.4%) {
    if (frontDistance >= 0.1 and frontDistance < 0.15) {
        steerFront = 6.59729 * frontDistance - 0.6567194999999991;
        return steerFront;
    }
    // Group 4 (81.5%) {
    else if (frontDistance >= 0.15 and frontDistance < 0.2) {
        steerFront = 7.87176344 * frontDistance - 1.1357735406249996;
        return steerFront;
    }
    // Group 5 (27.3%) {
    else if (frontDistance >= 0.2 and frontDistance < 0.25) {
        steerFront = 2.00958603 * frontDistance - 0.2662117564516128;
        return steerFront;
    }
    // Group 7 (40.1%) {
    else if (frontDistance >= 0.3 and frontDistance < 0.35) {
        steerFront = -1.50213189 * frontDistance + 0.6970611016322416;
        return steerFront;
    }
    // Group 8 (40.1%) {
    else if (frontDistance >= 0.35 and frontDistance < 0.4) {
        steerFront = -1.50213189 * frontDistance + 0.6970611016322416;
        return steerFront;
    }
    // Group 9 (35.1%) {
    else if (frontDistance >= 0.4 and frontDistance < 0.45) {
        steerFront = -2.04009895 * frontDistance + 1.005011740172413;
        return steerFront;
    }
    // Group 12 (39.8%) {
    else if (frontDistance >= 0.55 and frontDistance < 0.6) {
        steerFront = 2.0559964 * frontDistance - 1.0617851609038473;
        return steerFront;
    }
    // Group 32 (26.8%) {
    else if (frontDistance >= 1.55 and frontDistance < 1.6) {
        steerFront = -1.56710208 * frontDistance + 2.564695767789372;
        return steerFront;
    }
    // Group 37 (24.3%) {
    else if (frontDistance >= 1.8 and frontDistance < 1.85) {
        steerFront = 1.2503254 * frontDistance - 2.113012007816089;
        return steerFront;
    }
    // Group 38 (32.3%) {
    else if (frontDistance >= 1.85 and frontDistance < 1.9) {
        steerFront = -0.72512018 * frontDistance + 1.4690738894611204;
        return steerFront;
    }
    // Group 39 (54.3%) {
    else if (frontDistance >= 1.9 and frontDistance < 1.95) {
        steerFront = -3.60936984 * frontDistance + 7.011728014363628;
        return steerFront;
    }
    // Group 40 (36.1%) {
    else if (frontDistance >= 1.95 and frontDistance < 2) {
        steerFront = 1.08123544 * frontDistance - 2.021039579895316;
        return steerFront;
    }
    // Group 42 (27.2%) {
    else if (frontDistance >= 2.05 and frontDistance < 2.1) {
        steerFront = -2.47007854 * frontDistance + 5.2021500641173795;
        return steerFront;
    }
    // Group 46 (38.6%) {
    else if (frontDistance >= 2.25 and frontDistance < 2.3) {
        steerFront = 2.36785846 * frontDistance - 5.2555739473170835;
        return steerFront;
    }
    // Group 47 (55.1%) {
    else if (frontDistance >= 2.3 and frontDistance < 2.35) {
        steerFront = 1.61192609 * frontDistance - 3.6748125877321978;
        return steerFront;
    }
    // Group 48 (25.5%) {
    else if (frontDistance >= 2.35 and frontDistance < 2.4) {
        steerFront = 0.73306158 * frontDistance - 1.6340551488888995;
        return steerFront;
    }
    // Group 49 (44.4%) {
    else if (frontDistance >= 2.4 and frontDistance < 2.45) {
        steerFront = 1.66785506 * frontDistance - 3.958791068125067;
        return steerFront;
    }
    // Group 50 (24.8%) {
    else if (frontDistance >= 2.45 and frontDistance < 2.5) {
        steerFront = 1.47074951 * frontDistance - 3.4463072570212514;
        return steerFront;
    }
    // Group 51 (28.5%) {
    else if (frontDistance >= 2.5 and frontDistance < 2.55) {
        steerFront = -0.99585667 * frontDistance + 2.5957963872830314;
        return steerFront;
    }
    // Group 52 (82.7%) {
    else if (frontDistance >= 2.55 and frontDistance < 2.6) {
        steerFront = 5.96612547 * frontDistance - 15.217821794736905;
        return steerFront;
    }
    // Group 53 (29.6%) {
    else if (frontDistance >= 2.6 and frontDistance < 2.65) {
        steerFront = 1.06389941 * frontDistance - 2.700078482217599;
        return steerFront;
    }
    // Group 55 (53.7%) {
    else if (frontDistance >= 2.7 and frontDistance < 2.75) {
        steerFront = 0.66318692 * frontDistance - 2.700078482217599;
        return steerFront;
    }
    // Group 56 (30.1%) {
    else if (frontDistance >= 2.75 and frontDistance < 2.8) {
        steerFront = 0.68744883 * frontDistance - 1.7635385744594683;
        return steerFront;
    }
    // Group 57 (87.7%) {
    else if (frontDistance >= 2.8 and frontDistance < 2.85) {
        steerFront = -1.94919617 * frontDistance + 5.613187821666673;
        return steerFront;
    }
    // Group 58 (100.0%) {
    else if (frontDistance >= 2.85 and frontDistance < 2.9) {
        steerFront = -0.10001933 * frontDistance + 0.3060503100000018;
        return steerFront;
    }
    // Group 59 (100.0%) {
    else if (frontDistance >= 2.9 and frontDistance < 2.95) {
        steerFront = -18.293795 * frontDistance + 53.48385875000112;
        return steerFront;
    }
    // Group 60 (27.0%) {
    else if (frontDistance >= 2.95 and frontDistance < 3) {
        steerFront = -0.65919297 * frontDistance + 2.0857763575581254;
        return steerFront;
    }
    // Group 61 (32.9%) {
    else if (frontDistance >= 3 and frontDistance < 3.05) {
        steerFront = 0.97274071 * frontDistance - 2.807933012106588;
        return steerFront;
    }
    // Group 62 (32.9%) {
    else if (frontDistance >= 3.05 and frontDistance < 3.1) {
        steerFront = 0.97274071 * frontDistance - 2.807933012106588;
        return steerFront;
    }
    // Group 63 (44.0%) {
    else if (frontDistance >= 3.1 and frontDistance < 3.15) {
        steerFront = -2.59323014 * frontDistance + 8.235003027450912;
        return steerFront;
    }
    // Group 64 (42.4%) {
    else if (frontDistance >= 3.15 and frontDistance < 3.2) {
        steerFront = 0.68770974 * frontDistance - 2.037015081891106;
        return steerFront;
    }
    // Group 65 (42.4%) {
    else if (frontDistance >= 3.2 and frontDistance < 3.25) {
        steerFront = 0.68770974 * frontDistance - 2.037015081891106;
        return steerFront;
    }
    // Group 66 (34.7%) {
    else if (frontDistance >= 3.25 and frontDistance < 3.3) {
        steerFront = 5.9985065 * frontDistance - 19.496673084999543;
        return steerFront;
    }
    // Group 69 (100.0%) {
    else if (frontDistance >= 3.4 and frontDistance < 3.45) {
        steerFront = 0.74926 * frontDistance - 2.472478399999996;
        return steerFront;
    }
    // Group 70 (100.0%) {
    else if (frontDistance >= 3.45 and frontDistance < 3.5) {
        steerFront = 0.74926 * frontDistance - 2.472478399999996;
        return steerFront;
    }
    // Group 79 (83.9%) {
    else if (frontDistance >= 3.9 and frontDistance < 3.95) {
        steerFront = 9.596544 * frontDistance - 37.60346435999964;
        return steerFront;
    }

    // Default Case
    else {
        steerFront = 0;
        return steerFront;
    }
}

float sideSteer(float leftVoltage, float rightVoltage, float gsrBefore){

    float voltageDifference = abs(rightVoltage - leftVoltage);
    float steerLeftRight;

    // Constant value section
    // Values here are constant due to a lack of data. However, it seemed to have high accuracy

    if (voltageDifference <= 0.0002) {
        // If the voltage difference is 0, we just take the previous gsr value and multiply by 0.9
        steerLeftRight = gsrBefore * 0.9;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0004 and voltageDifference < 0.0005) {
        steerLeftRight = 0.120626737;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0005 and voltageDifference < 0.0008) {
        steerLeftRight = gsrBefore * 0.9;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0008 and voltageDifference < 0.0009) {
        steerLeftRight = 0.129724726;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0009 and voltageDifference < 0.0013) {
        steerLeftRight = gsrBefore * 0.9;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0013 and voltageDifference < 0.0014) {
        steerLeftRight = 0.145306395;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0035 and voltageDifference < 0.0036) {
        steerLeftRight = 0.116958102;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0026 and voltageDifference < 0.0027) {
        steerLeftRight = 0.11836379;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0039 and voltageDifference < 0.004) {
        steerLeftRight = 0.19093069;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.004 and voltageDifference < 0.0045) {
        steerLeftRight = 0.117954927;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0045 and voltageDifference < 0.005) {
        steerLeftRight = 0.112956903;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.005 and voltageDifference < 0.0055) {
        steerLeftRight = 0.09236473;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0055 and voltageDifference < 0.006) {
        steerLeftRight = 0.18143326;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.006 and voltageDifference < 0.0066) {
        steerLeftRight = 0.164936251;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.01 and voltageDifference < 0.0105) {
        steerLeftRight = 0.106833679;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0105 and voltageDifference < 0.0109) {
        steerLeftRight = 0.063975482;
        return steerLeftRight;
    }
    else if (voltageDifference >= 0.0109 and voltageDifference < 0.011) {
        steerLeftRight = 0.123381604;
        return steerLeftRight;
    }
    // Linear Function Section
    // Each functions were developed based on the Pearson correlation coefficient model

    else if (voltageDifference >= 0.0015 and voltageDifference < 0.002) {
        steerLeftRight = -35221695.08947108 * voltageDifference + 61928.36279107543;
        return steerLeftRight;
    }
    // Group 2 ~ 2.5 (37.5%) {
    else if (voltageDifference >= 0.002 and voltageDifference < 0.0025) {
        steerLeftRight = 35557465.76208925 * voltageDifference - 78148.12354230083;
        return steerLeftRight;
    }
    // Group 3 ~ 3.5 (27.7%) {
    else if (voltageDifference >= 0.003 and voltageDifference < 0.0035) {
        steerLeftRight = 21248832.41216514 * voltageDifference - 65380.900751726054;
        return steerLeftRight;
    }
    // Group 6 (15.6%) {
    else if (voltageDifference >= 0.005 and voltageDifference < 0.006) {
        steerLeftRight = 60.68868884 * voltageDifference - 0.21978821128620074;
        return steerLeftRight;
    }
    // Group 7 ~ 7.5 (21.0%) {
    else if (voltageDifference >= 0.007 and voltageDifference < 0.0075) {
        steerLeftRight = 78.15535195 * voltageDifference - 0.3782710108484515;
        return steerLeftRight;
    }
    // Group 7.5 ~ 8 (30.2%) {
    else if (voltageDifference >= 0.0075 and voltageDifference < 0.008) {
        steerLeftRight = -8060487.84280328 * voltageDifference + 63775.36085186425;
        return steerLeftRight;
    }
    // Group 9 (30.4%) {
    else if (voltageDifference >= 0.008 and voltageDifference < 0.009) {
        steerLeftRight = 103.14386239 * voltageDifference - 0.7540263611635712;
        return steerLeftRight;
    }
    // Group 10 (18.7%) {
    else if (voltageDifference >= 0.009 and voltageDifference < 0.01) {
        steerLeftRight = 28.77060515 * voltageDifference - 0.12074253178601208;
        return steerLeftRight;
    }
    // Group 11.5 (34.1%) { //Flagged
    else if (voltageDifference >= 0.011 and voltageDifference < 0.0115) {
        steerLeftRight = 22450484.29195487 * voltageDifference - 256576.89099948324;
        return steerLeftRight;
    }
    // Group 11.5 ~ 12 (18.0) {
    else if (voltageDifference >= 0.0115 and voltageDifference < 0.012) {
        steerLeftRight = -68.8909895 * voltageDifference + 0.9248761412106097;
        return steerLeftRight;
    }
    // Group 13 (29.2%) {
    else if (voltageDifference >= 0.012 and voltageDifference < 0.013) {
        steerLeftRight = -63.58763927 * voltageDifference + 0.8503078951726413;
        return steerLeftRight;
    }
    // Group 14 (72.0%) {
    else if (voltageDifference >= 0.013 and voltageDifference < 0.014) {
        steerLeftRight = -427.53849378 * voltageDifference + 5.898771363979959;
        return steerLeftRight;
    }
    // Group 15 (71.0%) {
    else if (voltageDifference >= 0.014 and voltageDifference < 0.015) {
        steerLeftRight = 147.02746632 * voltageDifference - 1.9894784809674784;
        return steerLeftRight;
    }
    // Group 16 (38.1%) {
    else if (voltageDifference >= 0.015 and voltageDifference < 0.016) {
        steerLeftRight = 46.30715899 * voltageDifference - 0.5471218254180528;
        return steerLeftRight;
    }
    // Group 17 (28.4%) {
    else if (voltageDifference >= 0.016 and voltageDifference < 0.017) {
        steerLeftRight = -119.76124496 * voltageDifference + 2.130697776104509;
        return steerLeftRight;
    }
    // Group 18 (24.9%) {
    else if (voltageDifference >= 0.017 and voltageDifference < 0.018) {
        steerLeftRight = -56.26268963 * voltageDifference + 1.0748760045350803;
        return steerLeftRight;
    }
    // Group 19 (26.1%) {
    else if (voltageDifference >= 0.018 and voltageDifference < 0.019) {
        steerLeftRight = -46.39342823 * voltageDifference + 0.9632583154955816;
        return steerLeftRight;
    }
    // Group 20 (50.7%) {
    else if (voltageDifference >= 0.019 and voltageDifference < 0.02) {
        steerLeftRight = -173.97463094 * voltageDifference + 3.510233794939442;
        return steerLeftRight;
    }
    // Group 21 (43.9%) {
    else if (voltageDifference >= 0.02 and voltageDifference < 0.021) {
        steerLeftRight = 203.80726017 * voltageDifference - 4.018599301994921;
        return steerLeftRight;
    }
    // Group 22 (48.9%) {
    else if (voltageDifference >= 0.021 and voltageDifference < 0.022) {
        steerLeftRight = -131.10318384 * voltageDifference + 2.9357768301345555;
        return steerLeftRight;
    }
    // Group 23 (41.1%) {
    else if (voltageDifference >= 0.022 and voltageDifference < 0.023) {
        steerLeftRight = -69.06295783 * voltageDifference + 2.9357768301345555;
        return steerLeftRight;
    }
    // Group 24 (89.1%) {
    else if (voltageDifference >= 0.023 and voltageDifference < 0.024) {
        steerLeftRight = -341.11458858 * voltageDifference + 8.17326398170884;
        return steerLeftRight;
    }
    // Group 25 (27.2%) {
    else if (voltageDifference >= 0.024 and voltageDifference < 0.025) {
        steerLeftRight = 27.88559209 * voltageDifference - 0.6205525673800425;
        return steerLeftRight;
    }
    // Group 26 (27.2%) {
    else if (voltageDifference >= 0.025 and voltageDifference < 0.026) {
        steerLeftRight = 27.88559209 * voltageDifference - 0.6205525673800425;
        return steerLeftRight;
    }
    // Group 27 (55.1%) {
    else if (voltageDifference >= 0.026 and voltageDifference < 0.027) {
        steerLeftRight = 232.30684969 * voltageDifference - 6.056668459226435;
        return steerLeftRight;
    }
    // Group 28 (32.9%) {
    else if (voltageDifference >= 0.027 and voltageDifference < 0.028) {
        steerLeftRight = 124.02143243 * voltageDifference - 3.300151000059235;
        return steerLeftRight;
    }
    // Group 29 (59.5%) {
    else if (voltageDifference >= 0.028 and voltageDifference < 0.029) {
        steerLeftRight = 236.06175218 * voltageDifference - 6.5868731530390745;
        return steerLeftRight;
    }
    // Group 30 (53.9%) {
    else if (voltageDifference >= 0.029 and voltageDifference < 0.03) {
        steerLeftRight = 73.84358041 * voltageDifference - 2.0413671617408915;
        return steerLeftRight;
    }
    // Group 31 (32.7%) {
    else if (voltageDifference >= 0.03 and voltageDifference < 0.031) {
        steerLeftRight = -59.79309038 * voltageDifference + 1.9713688743152877;
        return steerLeftRight;
    }
    // Group 32 (32.7%) {
    else if (voltageDifference >= 0.031 and voltageDifference < 0.032) {
        steerLeftRight = -59.79309038 * voltageDifference + 1.9713688743152877;
        return steerLeftRight;
    }
    // Group 33 (68.8%) {
    else if (voltageDifference >= 0.032 and voltageDifference < 0.033) {
        steerLeftRight = -74.19365773 * voltageDifference + 2.592141058721383;
        return steerLeftRight;
    }
    // Group 34 (68.8%) {
    else if (voltageDifference >= 0.033 and voltageDifference < 0.034) {
        steerLeftRight = -74.19365773 * voltageDifference + 2.592141058721383;
        return steerLeftRight;
    }
    // Group 35 (85.3%) {
    else if (voltageDifference >= 0.034 and voltageDifference < 0.035) {
        steerLeftRight = -27.85733023 * voltageDifference + 1.0238347788753475;
        return steerLeftRight;
    }
    // Group 36 (85.3%) {
    else if (voltageDifference >= 0.035 and voltageDifference < 0.036) {
        steerLeftRight = -27.85733023 * voltageDifference + 1.0238347788753475;
        return steerLeftRight;
    }
    // Group 37 (30.3%) {
    else if (voltageDifference >= 0.036 and voltageDifference < 0.037) {
        steerLeftRight = -52.98116665 * voltageDifference + 2.0438722938323126;
        return steerLeftRight;
    }
    // Group 38 (24.3%) {
    else if (voltageDifference >= 0.037 and voltageDifference < 0.038) {
        steerLeftRight = -24.82624564 * voltageDifference + 1.0179621048775431;
        return steerLeftRight;
    }
    // Group 39 (51.3%) {
    else if (voltageDifference >= 0.038 and voltageDifference < 0.039) {
        steerLeftRight = -75.07458235 * voltageDifference + 2.9249707136550676;
        return steerLeftRight;
    }
    // Group 40 (72.8%) {
    else if (voltageDifference >= 0.039 and voltageDifference < 0.04) {
        steerLeftRight = 96.36536535 * voltageDifference - 3.636444802683062;
        return steerLeftRight;
    }
    // Group 41 (71.0%) {
    else if (voltageDifference >= 0.04 and voltageDifference < 0.041) {
        steerLeftRight = -35.03713596 * voltageDifference + 1.5458015716460265;
        return steerLeftRight;
    }
    // Group 42 (71.0%) {
    else if (voltageDifference >= 0.041 and voltageDifference < 0.042) {
        steerLeftRight = -35.03713596 * voltageDifference + 1.5458015716460265;
        return steerLeftRight;
    }
    // Group 43 (84.6%) {
    else if (voltageDifference >= 0.042 and voltageDifference < 0.043) {
        steerLeftRight = -191.04409755 * voltageDifference + 8.247579901888322;
        return steerLeftRight;
    }
    // Group 44 (91.8%) {
    else if (voltageDifference >= 0.043 and voltageDifference < 0.044) {
        steerLeftRight = -218.29976138 * voltageDifference + 9.592612066403154;
        return steerLeftRight;
    }
    // Group 45 (100.0%) { FLAGGED
    else if (voltageDifference >= 0.044 and voltageDifference < 0.045) {
        steerLeftRight = abs(150.11777606 * voltageDifference - 6.769552778318174);
        return steerLeftRight;
    }
    // Group 46 (100.0%) {
    else if (voltageDifference >= 0.045 and voltageDifference < 0.046) {
        steerLeftRight = 150.11777606 * voltageDifference - 6.769552778318174;
        return steerLeftRight;
    }
    // Group 47 (47.4%) {
    else if (voltageDifference >= 0.046 and voltageDifference < 0.047) {
        steerLeftRight = 147.35543754 * voltageDifference - 6.727841110511932;
        return steerLeftRight;
    }   
    // Group 49 (31.2%) {
    else if (voltageDifference >= 0.048 and voltageDifference < 0.049) {
        steerLeftRight = -177.41065934 * voltageDifference + 8.707053273082494;
        return steerLeftRight;
    }
    // Group 50 (51.3%) {
    else if (voltageDifference >= 0.049 and voltageDifference < 0.05) {
        steerLeftRight = -223.43672586 * voltageDifference + 11.180647394903497;
        return steerLeftRight;
    }
    // Group 51 (36.6%) {
    else if (voltageDifference >= 0.05 and voltageDifference < 0.051) {
        steerLeftRight = 30.71780152 * voltageDifference - 1.5071839398662443;
        return steerLeftRight;
    }
    // Group 52 (71.8%) {
    else if (voltageDifference >= 0.051 and voltageDifference < 0.052) {
        steerLeftRight = 58.68766263 * voltageDifference - 2.9185862078941365;
        return steerLeftRight;
    }
    // Group 53 (49.7%) {
    else if (voltageDifference >= 0.052 and voltageDifference < 0.053) {
        steerLeftRight = 107.20193341 * voltageDifference - 5.553073423238474;
        return steerLeftRight;
    }
    // Group 54 (100.0%) {
    else if (voltageDifference >= 0.053 and voltageDifference < 0.054) {
        steerLeftRight = 648.13838611 * voltageDifference - 34.46642738630328;
        return steerLeftRight;
    }
    // Group 55 (29.4%) {
    else if (voltageDifference >= 0.054 and voltageDifference < 0.055) {
        steerLeftRight = 21.12405203 * voltageDifference - 1.0592742016100545;
        return steerLeftRight;
    }
    // Group 56 (29.4%) {
    else if (voltageDifference >= 0.055 and voltageDifference < 0.056) {
        steerLeftRight = 21.12405203 * voltageDifference - 1.0592742016100545;
        return steerLeftRight;
    }
    // Group 57 (29.4%) {
    else if (voltageDifference >= 0.056 and voltageDifference < 0.057) {
        steerLeftRight = 21.12405203 * voltageDifference - 1.0592742016100545;
        return steerLeftRight;
    }
    // Group 58 (40.1%) {
    else if (voltageDifference >= 0.057 and voltageDifference < 0.058) {
        steerLeftRight = 44.1511947 * voltageDifference - 2.415685760413696;
        return steerLeftRight;
    }
    // Group 59 (40.6%) {
    else if (voltageDifference >= 0.058 and voltageDifference < 0.059) {
        steerLeftRight = 115.97851308 * voltageDifference - 6.595549455487812;
        return steerLeftRight;
    }
    // Group 60 (79.0%) {
    else if (voltageDifference >= 0.059 and voltageDifference < 0.06) {
        steerLeftRight = -302.45906985 * voltageDifference + 18.18602954883787;
        return steerLeftRight;
    }
    // Group 61 (64.4%) {
    else if (voltageDifference >= 0.06 and voltageDifference < 0.061) {
        steerLeftRight = 71.26042484 * voltageDifference - 4.20198816032044;
        return steerLeftRight;
    }
    // Group 62 (65.8%) {
    else if (voltageDifference >= 0.061 and voltageDifference < 0.062) {
        steerLeftRight = 201.24447962 * voltageDifference - 12.168357900444683;
        return steerLeftRight;
    }
    // Group 63 (91.1%) {
    else if (voltageDifference >= 0.062 and voltageDifference < 0.063) {
        steerLeftRight = 85.2790379 * voltageDifference - 5.306710237634773;
        return steerLeftRight;
    }
    // Group 64 (55.6%) {
    else if (voltageDifference >= 0.063 and voltageDifference < 0.064) {
        steerLeftRight = 61.39714872 * voltageDifference - 3.78876693821373;
        return steerLeftRight;
    }
    // Group 65 (80.4%) {
    else if (voltageDifference >= 0.064 and voltageDifference < 0.065) {
        steerLeftRight = 295.64301476 * voltageDifference - 18.929146225921233;
        return steerLeftRight;
    }
    // Group 66 (78.4%) {
    else if (voltageDifference >= 0.065 and voltageDifference < 0.066) {
        steerLeftRight = -170.29065483 * voltageDifference + 11.285865350478922;
        return steerLeftRight;
    }
    // Group 67 (39.7%) {
    else if (voltageDifference >= 0.066 and voltageDifference < 0.067) {
        steerLeftRight = 48.67727523 * voltageDifference - 3.138687306043849;
        return steerLeftRight;
    }
    // Group 68 (39.7%) {
    else if (voltageDifference >= 0.067 and voltageDifference < 0.068) {
        steerLeftRight = 48.67727523 * voltageDifference - 3.138687306043849;
        return steerLeftRight;
    }
    // Group 69 (40.7%) {
    else if (voltageDifference >= 0.068 and voltageDifference < 0.069) {
        steerLeftRight = 249.00325004 * voltageDifference - 16.783622233017365;
        return steerLeftRight;
    }
    // Group 70 (28.6%) {
    else if (voltageDifference >= 0.069 and voltageDifference < 0.07) {
        steerLeftRight = -54.3553244 * voltageDifference + 3.8974700284713792;
        return steerLeftRight;
    }
    // Group 73 (50.1%) {
    else if (voltageDifference >= 0.072 and voltageDifference < 0.073) {
        steerLeftRight = 131.57793097 * voltageDifference - 9.656969738719791;
        return steerLeftRight;
    }
    // Group 74 (50.1%) {
    else if (voltageDifference >= 0.073 and voltageDifference < 0.074) {
        steerLeftRight = 131.57793097 * voltageDifference - 9.656969738719791;
        return steerLeftRight;
    }
    // Group 75 (30.7%) {
    else if (voltageDifference >= 0.074 and voltageDifference < 0.075) {
        steerLeftRight = 122.80821232 * voltageDifference - 9.00293509830189;
        return steerLeftRight;
    }
    // Group 76 (28.7%) {
    else if (voltageDifference >= 0.075 and voltageDifference < 0.076) {
        steerLeftRight = -45.32362489 * voltageDifference + 3.5164197929983807;
        return steerLeftRight;
    }
    // Group 77 (43.3%) {
    else if (voltageDifference >= 0.076 and voltageDifference < 0.077) {
        steerLeftRight = 96.40695691 * voltageDifference - 7.268512831042963;
        return steerLeftRight;
    }
    // Group 78 (100.0%) {
    else if (voltageDifference >= 0.077 and voltageDifference < 0.078) {
        steerLeftRight = -150.06647027 * voltageDifference + 11.70550300552836;
        return steerLeftRight;
    }
    // Group 79 (27.9%) {
    else if (voltageDifference >= 0.078 and voltageDifference < 0.079) {
        steerLeftRight = -45.62935804 * voltageDifference + 3.7043238479161213;
        return steerLeftRight;
    }
    // Group 80 (100.0%) {
    else if (voltageDifference >= 0.079 and voltageDifference < 0.08) {
        steerLeftRight = -341.1582597 * voltageDifference + 27.163684179657732;
        return steerLeftRight;
    }
    // Group 81 (27.4%) {
    else if (voltageDifference >= 0.08 and voltageDifference < 0.081) {
        steerLeftRight = 29.02478379 * voltageDifference - 2.172545585011335;
        return steerLeftRight;
    }
    // Group 82 (100.0%) {
    else if (voltageDifference >= 0.081 and voltageDifference < 0.082) {
        steerLeftRight = 450.29577077 * voltageDifference - 36.61146539766238;
        return steerLeftRight;
    }
    // Group 83 (31.1%) {
    else if (voltageDifference >= 0.082 and voltageDifference < 0.083) {
        steerLeftRight = 32.64695213 * voltageDifference - 2.5701368502428137;
        return steerLeftRight;
    }
    // Group 84 (31.1%) {
    else if (voltageDifference >= 0.083 and voltageDifference < 0.084) {
        steerLeftRight = 32.64695213 * voltageDifference - 2.5701368502428137;
        return steerLeftRight;
    
    }
    // Group 85 (63.4%) {
    else if (voltageDifference >= 0.084 and voltageDifference < 0.085) {
        steerLeftRight = 184.21898567 * voltageDifference - 15.49628871160195;
        return steerLeftRight;
    }
    // Group 86 (34.7%) {
    else if (voltageDifference >= 0.085 and voltageDifference < 0.086) {
        steerLeftRight = 78.9504529 * voltageDifference - 6.6515056898273155;
        return steerLeftRight;
    }
    // Group 87 (29.9%) {
    else if (voltageDifference >= 0.086 and voltageDifference < 0.087) {
        steerLeftRight = -132.46303148 * voltageDifference + 11.574641202051586;
        return steerLeftRight;
    }
    // Group 88 (52.1%) {
    else if (voltageDifference >= 0.087 and voltageDifference < 0.088) {
        steerLeftRight = -97.92394544 * voltageDifference + 8.64891727571354;
        return steerLeftRight;
    }
    // Group 89 (97.7%) {
    else if (voltageDifference >= 0.088 and voltageDifference < 0.089) {
        steerLeftRight = 54.59175147 * voltageDifference - 4.8202793318036;
        return steerLeftRight;
    }
    // Group 90 (97.7%) {
    else if (voltageDifference >= 0.089 and voltageDifference < 0.09) {
        steerLeftRight = 54.59175147 * voltageDifference - 4.8202793318036;
        return steerLeftRight;
    }
    // Group 91 (40.9%) {
    else if (voltageDifference >= 0.09 and voltageDifference < 0.091) {
        steerLeftRight = 58.84736616 * voltageDifference - 5.248755145764711;
        return steerLeftRight;
    }
    // Group 92 (40.9%) {
    else if (voltageDifference >= 0.091 and voltageDifference < 0.092) {
        steerLeftRight = 58.84736616 * voltageDifference - 5.248755145764711;
        return steerLeftRight;
    }
    // Group 93 (100.0%) {
    else if (voltageDifference >= 0.092 and voltageDifference < 0.093) {
        steerLeftRight = -245.62135724 * voltageDifference + 23.020623974916656;
        return steerLeftRight;
    }
    // Group 94 (100.0%) {
    else if (voltageDifference >= 0.093 and voltageDifference < 0.094) {
        steerLeftRight = -245.62135724 * voltageDifference + 23.020623974916656;
        return steerLeftRight;
    }
    // Group 95 (88.3%) {
    else if (voltageDifference >= 0.094 and voltageDifference < 0.095) {
        steerLeftRight = -255.84753184 * voltageDifference + 24.327432267811492;
        return steerLeftRight;
    }
    // Group 97 (42.1%) {
    else if (voltageDifference >= 0.096 and voltageDifference < 0.097) {
        steerLeftRight = -188.75796847 * voltageDifference + 18.34048963427753;
        return steerLeftRight;
    }
    // Group 98 (95.6%) {
    else if (voltageDifference >= 0.097 and voltageDifference < 0.098) {
        steerLeftRight = 482.14289916 * voltageDifference - 46.757762093043866;
        return steerLeftRight;
    }
    // Group 99 (25.1%) {
    else if (voltageDifference >= 0.098 and voltageDifference < 0.099) {
        steerLeftRight = 48.67845466 * voltageDifference - 4.559601896875875;
        return steerLeftRight;
    }
    // Group 100 (70.7%) {
    else if (voltageDifference >= 0.099 and voltageDifference < 0.1) {
        steerLeftRight = -62.18333956 * voltageDifference + 6.36452364978183;
        return steerLeftRight;
    }
    // Group 101 (100.0%) {
    else if (voltageDifference >= 0.1 and voltageDifference < 0.101) {
        steerLeftRight = -313.81606037 * voltageDifference + 31.630503461351548;
        return steerLeftRight;
    }
    // Group 102 (70.7%) {
    else if (voltageDifference >= 0.101 and voltageDifference < 0.102) {
        steerLeftRight = -62.18333956 * voltageDifference + 6.36452364978183;
        return steerLeftRight;
    }
    // Group 103 (27.4%) {
    else if (voltageDifference >= 0.102 and voltageDifference < 0.103) {
        steerLeftRight = 40.94631196 * voltageDifference - 4.105160981845967;
        return steerLeftRight;
    }
    // Group 104 (61.0%) {
    else if (voltageDifference >= 0.103 and voltageDifference < 0.104) {
        steerLeftRight = 272.83957055 * voltageDifference - 28.135417249710954;
        return steerLeftRight;
    }
    // Group 105 (100.0%) {
    else if (voltageDifference >= 0.104 and voltageDifference < 0.105) {
        steerLeftRight = 300.20032945 * voltageDifference - 31.213628633085943;
        return steerLeftRight;
    }
    // Group 106 (100.0%) {
    else if (voltageDifference >= 0.105 and voltageDifference < 0.106) {
        steerLeftRight = 68.20976661 * voltageDifference - 7.027821079098253;
        return steerLeftRight;
    }
    // Group 107 (95.2%) {
    else if (voltageDifference >= 0.106 and voltageDifference < 0.107) {
        steerLeftRight = 310.39939134 * voltageDifference - 33.118748121414995;
        return steerLeftRight;
    }
    // Group 108 (95.2%) {
    else if (voltageDifference >= 0.107 and voltageDifference < 0.108) {
        steerLeftRight = 310.39939134 * voltageDifference - 33.118748121414995;
        return steerLeftRight;
    }
    // Group 109 (100.0%) {
    else if (voltageDifference >= 0.108 and voltageDifference < 0.109) {
        steerLeftRight = 75.05101809 * voltageDifference - 8.10340789336121;
        return steerLeftRight;
    }
    // Group 110 (100.0%) {
    else if (voltageDifference >= 0.109 and voltageDifference < 0.11) {
        steerLeftRight = 75.05101809 * voltageDifference - 8.10340789336121;
        return steerLeftRight;
    }
    // Group 115 (24.1%) {
    else if (voltageDifference >= 0.114 and voltageDifference < 0.115) {
        steerLeftRight = 21.38922394 * voltageDifference - 2.357146576471119;
        return steerLeftRight;
    }
    // Group 116 (28.0%) {
    else if (voltageDifference >= 0.115 and voltageDifference < 0.116) {
        steerLeftRight = -88.70599945 * voltageDifference + 10.325277987801039;
        return steerLeftRight;
    }
    // Group 117 (40.0%) {
    else if (voltageDifference >= 0.116 and voltageDifference < 0.117) {
        steerLeftRight = -102.35084475 * voltageDifference + 12.046634753555159;
        return steerLeftRight;
    }
    // Group 121 (100.0%) {
    else if (voltageDifference >= 0.12 and voltageDifference < 0.121) {
        steerLeftRight = -538.94868062 * voltageDifference + 66.10725838451344;
        return steerLeftRight;
    }
    // Group 122 (100.0%) {
    else if (voltageDifference >= 0.121 and voltageDifference < 0.122) {
        steerLeftRight = -538.94868062 * voltageDifference + 66.10725838451344;
        return steerLeftRight;
    }
    // Group 123 (47.3%) {
    else if (voltageDifference >= 0.122 and voltageDifference < 0.123) {
        steerLeftRight = -63.23930752 * voltageDifference + 7.886997323932255;
        return steerLeftRight;
    }
    // Group 124 (47.3%) {
    else if (voltageDifference >= 0.123 and voltageDifference < 0.124) {
        steerLeftRight = -63.23930752 * voltageDifference + 7.886997323932255;
        return steerLeftRight;
    }
    // Group 125 (100.0%) {
    else if (voltageDifference >= 0.124 and voltageDifference < 0.125) {
        steerLeftRight = 518.43121019 * voltageDifference - 64.42755196261044;
        return steerLeftRight;
    }
    // Group 126 (83.5%) {
    else if (voltageDifference >= 0.125 and voltageDifference < 0.126) {
        steerLeftRight = 242.19943024 * voltageDifference - 29.98458926630578;
        return steerLeftRight;
    }
    
    // Does not exist
    else {
        steerLeftRight = 0;
        return steerLeftRight;
    }
}
    



