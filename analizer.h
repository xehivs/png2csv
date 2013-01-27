//
//  analizer.h
//  png2csv
//
//  Created by Paweł Ksieniewicz on 19.01.2013.
//  Copyright (c) 2013 Paweł Ksieniewicz. All rights reserved.
//

#ifndef __png2csv__analizer__
#define __png2csv__analizer__

#include <iostream>
#include "pngmatrix.h"
#include "patto.h"
#include "structures.h"

/*
 1 3 15429046
 - 5 589824
 0 5 672785844850
 2 5 673340286496
 3 5 673347373682
 4 5 217935742150
 5 5 610709637746
 6 5 672736561778
 7 5 37795291928
 8 5 672820447858
 9 5 672786844274
 */

class analizer {
    // static config
    char *chars = (char *) "1-023456789";
    int widths[11] = {3,5,5,5,5,5,5,5,5,5,5,};
    unsigned long long int patterns[11] = {15429046, 589824, 672785844850, 673340286496, 673347373682, 217935742150, 610709637746, 672736561778, 37795291928, 672820447858, 672786844274};
    
    // skala zaczyna się od 63
    frame temperature_scale_frame = {51,30,33,86};
    frame pressure_scale_frame = {221,30,33,86};
    frame wind_scale_frame = {307,30,33,86};
    
    range temperature_range = {58,76};
    range pressure_range = {230,76};
    range wind_range = {316,76};
    
    // dane skali
    int temperature_v1=0, temperature_v3=0, temperature_r1=0, temperature_r3=0;
    int pressure_v1=0, pressure_v3=0, pressure_r1=0, pressure_r3=0;
    int wind_v1=0, wind_v3=0, wind_r1=0, wind_r3=0;
    
    // obiekty
    patto *pattern_generator = new patto;
    
    // parametry pliku
    char *filename;
    time_t epch;
    int station_id;
    
    // metody prywatne
    float temperature_with_column(int);
    int pressure_with_column(int);
    int wind_max_with_column(int);
    int wind_avg_with_column(int);
    
    void set_scales();
    void set_date();
    void set_station_id();
    
    void analize_frame(frame);
    
    int column_for_hour_interval(int);
    time_t timestamp_for_hour_interval(int);
    
public:
        
    void load_file(char *);
    void println_for_hour_interval(int);

};

#endif /* defined(__png2csv__analizer__) */
