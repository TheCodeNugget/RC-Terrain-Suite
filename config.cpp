class CfgPatches {
	class RnCTS {
		name="R&C Terrain Suite";
		author="KenTheNugget";
		units[]={};
		weapons[]={};
		requiredVersion=1;
		requiredAddons[]= {
			"3den"
		};
		fileName="RnCTS.pbo";
		is3DENmod = 1;
	};
};

class CfgUserActions {
	class RNC_snap2Surface { // This class name is used for internal representation and also for the inputAction command.
		displayName = "Snap To Surface";
		tooltip = "Snap to surface.";
		onActivate = "";		// _this is always true.
		onDeactivate = "[1] spawn RNC_fnc_objectModifier";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
		modifierBlocking=1;
	};
	
	class RNC_orient2Sea { // This class name is used for internal representation and also for the inputAction command.
		displayName = "Orient to Sea Normal";
		tooltip = "Snap to surface keybind.";
		onActivate = "";		// _this is always true.
		onDeactivate = "[2] spawn RNC_fnc_objectModifier";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
		modifierBlocking=1;
	};
	
	class RNC_orient2Ground { // This class name is used for internal representation and also for the inputAction command.
		displayName = "Orient to Terrain Normal";
		tooltip = "Orient to Terrain Normal.";
		onActivate = "";		// _this is always true.
		onDeactivate = "[3] spawn RNC_fnc_objectModifier";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
		modifierBlocking=1;
	};
	
	class RNC_openAttributes { // This class name is used for internal representation and also for the inputAction command.
		displayName = "Open Attributes";
		tooltip = "Open Attributes on selected.";
		onActivate = "";		// _this is always true.
		onDeactivate = "[4] spawn RNC_fnc_objectModifier";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
		modifierBlocking=1;
	};
};

class UserActionGroups {
	class ModSection { // Unique classname of your category.
		name = "R&C Terrain Suite"; // Display name of your category.
		isAddon = 1;
		group[] = {"RNC_snap2Surface", "RNC_orient2Sea", "RNC_orient2Ground", "RNC_openAttributes"}; // List of all actions inside this category.
	};
};

class CfgFunctions {
	class RNC {
		tag="RNC";
		class functions {
			file="\RnCTS\functions";
			class exportHF {};
			class objectModifier {};
		};
	};
};

class RscPicture;
class RscText;
class RscProgress;
class RNC_ProgressBar {
	show=0;
	movingEnable=0;
	idd=-1;
	onLoad="uiNamespace setVariable [""RNC_ProgressBar_Display"", (_this select 0)];";
	onUnload="uiNamespace setVariable [""RNC_ProgressBar_Display"", nil];";
	class ControlsBackground
	{
		class RNC_Select_Mainback: RscPicture
		{
			idc=-1;
			x="0.2 * safezoneW + safezoneX";
			y="0.302 * safezoneH + safezoneY";
			w="0.6 * safezoneW";
			h="0.02 * safezoneH";
			moving=0;
			text="#(argb,8,8,3)color(0,0,0,0.7)";
		};
	};
	class Controls
	{
		class RNC_ProgressBar_Text: RscText
		{
			idc=34516;
			text="";
			style=2;
			x="0.2 * safezoneW + safezoneX";
			y="0.268 * safezoneH + safezoneY";
			w="0.6 * safezoneW";
			h="0.04 * safezoneH";
		};
		class RNC_ProgressBar_Bar: RscProgress
		{
			idc=34517;
			text="";
			x="0.2 * safezoneW + safezoneX";
			y="0.302 * safezoneH + safezoneY";
			w="0.6 * safezoneW";
			h="0.02 * safezoneH";
			colorFrame[]={0,0,0,1};
		};
	};
};

class ctrlMenuStrip;
class display3DEN {
	class Controls {
		class MenuStrip: ctrlMenuStrip {
			class Items {
				class MissionExport {
					items[]+= {
						"RNCExportHF",
					};
				};
				class RNCExportHF {
					text="Export Heightfield";
					data="RNCExportHF";
					action="[] spawn RNC_fnc_exportHF;";
				};
			};
		};
	};
};

class Cfg3DEN {
	class Notifications {
		class RNC_exportDone {
			text="Heightfield Exported";
			isWarning=0;
		};
		
		class RNC_snapped {
			text="Objects Snapped to Ground";
			isWarning=0;
		};
		
		class RNC_seaOriented {
			text="Objects Oriented to Sea";
			isWarning=0;
		};
		
		class RNC_groundOriented {
			text="Objects Oriented to Ground";
			isWarning=0;
		};
		
		class RNC_noObjectsSelected {
			text="Objects Oriented to Ground";
			isWarning=0;
		};
	};
};
