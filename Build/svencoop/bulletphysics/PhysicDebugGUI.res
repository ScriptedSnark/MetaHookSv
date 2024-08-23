"bulletphysics/PhysicDebugGUI.res"
{
	"PhysicDebugGUI"
	{
		"ControlName"	"Frame"
		"fieldName"		"PhysicDebugGUI"
		"wide"			"640"
		"tall"			"480"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"	"0"
	}
	"TopBar"
	{
		"ControlName"	"Panel"
		"fieldName"		"TopBar"
		"xpos"			"0"
		"ypos"			"0"
		"wide"			"640"
		"tall"			"48"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"0"
		"tabPosition"	"0"
	}
	"BottomBarBlank"
	{
		"ControlName"	"Panel"
		"fieldName"		"BottomBarBlank"
		"xpos"			"0"
		"ypos"			"r72"
		"wide"			"640"
		"tall"			"72"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"	"0"
	}
	"InspectContentLabel"
	{
		"ControlName"	"Label"
		"fieldName"		"InspectContentLabel"
		"xpos"			"24"
		"ypos"			"r72"
		"wide"			"1280"
		"tall"			"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"0"
		"enabled"		"1"
		"tabPosition"	"0"
		"textAlignment"	"west"
	}
	"InspectContentLabel2"
	{
		"ControlName"	"Label"
		"fieldName"		"InspectContentLabel2"
		"xpos"			"24"
		"ypos"			"r48"
		"wide"			"1280"
		"tall"			"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"0"
		"enabled"		"1"
		"tabPosition"	"0"
		"textAlignment"	"west"
	}
	"InspectContentLabel3"
	{
		"ControlName"	"Label"
		"fieldName"		"InspectContentLabel3"
		"xpos"			"24"
		"ypos"			"r24"
		"wide"			"1280"
		"tall"			"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"0"
		"enabled"		"1"
		"tabPosition"	"0"
		"textAlignment"	"west"
	}
	"InspectModeLabel"
	{
		"ControlName"	"Label"
		"fieldName"		"InspectModeLabel"
		"xpos"			"20"
		"ypos"			"48"
		"wide"			"240"
		"tall"			"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"	"0"
		"textAlignment"	"west"
	}
	"EditModeLabel"
	{
		"ControlName"	"Label"
		"fieldName"		"EditModeLabel"
		"xpos"			"20"
		"ypos"			"72"
		"wide"			"360"
		"tall"			"80"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"	"0"
		"textAlignment"	"northwest"
	}
	"Reload"
	{
		"ControlName"		"Button"
		"fieldName"		"Reload"
		"xpos"		"70"
		"ypos"		"8"
		"wide"		"120"
		"tall"		"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#BulletPhysics_Reload"
		"textAlignment"		"center"
		"command"		"Reload"
		"tooltiptext"		"#BulletPhysics_Reload_ToolTips"
	}
	"Save"
	{
		"ControlName"		"Button"
		"fieldName"		"Save"
		"xpos"		"200"
		"ypos"		"8"
		"wide"		"120"
		"tall"		"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#BulletPhysics_Save"
		"textAlignment"		"center"
		"command"			"SaveOpenPrompt"
		"tooltiptext"		"#BulletPhysics_Save_ToolTips"
	}
	"InspectMode"
	{
		"ControlName"		"ComboBox"
		"fieldName"		"InspectMode"
		"xpos"		"340"
		"ypos"		"8"
		"wide"		"120"
		"tall"		"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"textHidden"	"0"
		"editable"		"0"
		"maxchars"		"-1"
	}
	"Close"
	{
		"ControlName"		"Button"
		"fieldName"		"Close"
		"xpos"		"r70"
		"ypos"		"8"
		"wide"		"60"
		"tall"		"24"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"0"
		"labelText"		"#GameUI_Close"
		"textAlignment"		"center"
		"command"		"Close"
	}
}
