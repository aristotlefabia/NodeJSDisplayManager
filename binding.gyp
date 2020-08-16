{
  "targets": [
    {
      "target_name": "display_manager",
      "sources": [
        "display_device_manager.cpp",
		"display_device_manager_if.cpp",
        "display_manager.cc",
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
