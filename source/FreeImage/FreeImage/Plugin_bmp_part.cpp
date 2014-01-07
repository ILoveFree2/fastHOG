
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
		}
	}
}
