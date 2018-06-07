// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GeographicLibWrapper.h"

#define LOCTEXT_NAMESPACE "FGeographicLibWrapperModule"

void FGeographicLibWrapperModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
    // Alternatively: const Geocentric& earth = Geocentric::WGS84();
    const double homeLat = 43.32, homeLon = 73.21, homeAlt = 0.0;
    const double offsetX = 0.03, offsetY = -0.01, offsetZ = 0.0;
    double scale = 1000.0;
    
    LocalCartesian proj(homeLat, homeLon, homeAlt, earth);
 
    // XYZ to LLA
    double lat, lon, alt;
    proj.Reverse(offsetX * scale, offsetY * scale, offsetZ * scale, lat, lon, alt);
    

    // LLA to XYZ
    double x, y, z;
    proj.Forward(lat, lon, alt, x, y, z);
    x /= scale;
    y /= scale;
    z /= scale;

	/*
    cout << "~ ~ ~ cpp ~ ~ ~" << "\n";
    cout << "LLA home point: " << homeLat << " " << homeLon << " " << homeAlt << "\n";
    cout << "+ XYZ offset: " << offsetX << " " << offsetY << " " << offsetZ << "\n";
    cout << " . . . . . . . ." << "\n";
    cout << "As LLA: " << lat << " " << lon << " " << alt << "\n";
    cout << "Back to XYZ: " << x << " " << y << " " << z << "\n";
    cout << "~ ~ ~ ~ ~ ~ ~ ~" << "\n";
	*/
}

void FGeographicLibWrapperModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGeographicLibWrapperModule, GeographicLibWrapper)