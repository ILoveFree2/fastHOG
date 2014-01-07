
// =====================================================================
// Plugin System Initialization
// =====================================================================

void DLL_CALLCONV
FreeImage_Initialise(BOOL load_local_plugins_only) {
	if (s_plugin_reference_count++ == 0) {
		
		// initialise the TagLib singleton
		TagLib& s = TagLib::instance();

		// internal plugin initialization

		s_plugins = new(std::nothrow) PluginList;

		if (s_plugins) {
			/* NOTE : 
			The order used to initialize internal plugins below MUST BE the same order 
			as the one used to define the FREE_IMAGE_FORMAT enum. 
			*/
			s_plugins->AddNode(InitBMP);
		        s_plugins->AddNode(InitPNG);
// TODO	enable		plugins->AddNode(InitJPEG);
// TODO enable	        s_plugins->AddNode(InitGIF);
//			s_plugins->AddNode(InitICO);
//			s_plugins->AddNode(InitJNG);
//			s_plugins->AddNode(InitKOALA);
//			s_plugins->AddNode(InitIFF);
//			s_plugins->AddNode(InitMNG);
//			s_plugins->AddNode(InitPNM, NULL, "PBM", "Portable Bitmap (ASCII)", "pbm", "^P1");
//			s_plugins->AddNode(InitPNM, NULL, "PBMRAW", "Portable Bitmap (RAW)", "pbm", "^P4");
//			s_plugins->AddNode(InitPCD);
//			s_plugins->AddNode(InitPCX);
//			s_plugins->AddNode(InitPNM, NULL, "PGM", "Portable Greymap (ASCII)", "pgm", "^P2");
//			s_plugins->AddNode(InitPNM, NULL, "PGMRAW", "Portable Greymap (RAW)", "pgm", "^P5");
//			s_plugins->AddNode(InitPNM, NULL, "PPM", "Portable Pixelmap (ASCII)", "ppm", "^P3");
//			s_plugins->AddNode(InitPNM, NULL, "PPMRAW", "Portable Pixelmap (RAW)", "ppm", "^P6");
//			s_plugins->AddNode(InitRAS);
//			s_plugins->AddNode(InitTARGA);
//			s_plugins->AddNode(InitTIFF);
//			s_plugins->AddNode(InitWBMP);
//			s_plugins->AddNode(InitPSD);
//			s_plugins->AddNode(InitCUT);
//			s_plugins->AddNode(InitXBM);
//			s_plugins->AddNode(InitXPM);
//			s_plugins->AddNode(InitDDS);
// 			s_plugins->AddNode(InitHDR);
//			s_plugins->AddNode(InitG3);
//			s_plugins->AddNode(InitSGI);
//			s_plugins->AddNode(InitEXR);
//			s_plugins->AddNode(InitJ2K);
//			s_plugins->AddNode(InitJP2);
//			s_plugins->AddNode(InitPFM);
//			s_plugins->AddNode(InitPICT);
//			s_plugins->AddNode(InitRAW);
		}
	}
}
