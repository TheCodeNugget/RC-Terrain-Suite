////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.10
//https://mikero.bytex.digital/Downloads
//'now' is Mon Sep 11 19:12:34 2023 : 'file' last modified on Tue Jun 20 23:10:47 2023
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class RnCTS
	{
		name = "R&C Terrain Suite";
		author = "KenTheNugget";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"3den"};
		fileName = "RnCTS.pbo";
		is3DENmod = 1;
	};
};
class CfgUserActions
{
	class RnCTS_snap2Surface
	{
		displayName = "Snap To Surface";
		tooltip = "Snap to surface.";
		onActivate = "";
		onDeactivate = "[1] spawn RnCTS_fnc_objectModifier";
		onAnalog = "";
		analogChangeThreshold = 0.1;
		modifierBlocking = 1;
	};
	class RnCTS_orient2Sea
	{
		displayName = "Orient to Sea Normal";
		tooltip = "Snap to surface keybind.";
		onActivate = "";
		onDeactivate = "[2] spawn RnCTS_fnc_objectModifier";
		onAnalog = "";
		analogChangeThreshold = 0.1;
		modifierBlocking = 1;
	};
	class RnCTS_orient2Ground
	{
		displayName = "Orient to Terrain Normal";
		tooltip = "Orient to Terrain Normal.";
		onActivate = "";
		onDeactivate = "[3] spawn RnCTS_fnc_objectModifier";
		onAnalog = "";
		analogChangeThreshold = 0.1;
		modifierBlocking = 1;
	};
	class RnCTS_openAttributes
	{
		displayName = "Open Attributes";
		tooltip = "Open Attributes on selected.";
		onActivate = "";
		onDeactivate = "[4] spawn RnCTS_fnc_objectModifier";
		onAnalog = "";
		analogChangeThreshold = 0.1;
		modifierBlocking = 1;
	};
	class RnCTS_rotateLeft
	{
		displayName = "Rotate Left";
		tooltip = "Rotate Selected Objects Left to the Rotation Grid Increment.";
		onActivate = "";
		onDeactivate = "[5] spawn RnCTS_fnc_objectModifier";
		onAnalog = "";
		analogChangeThreshold = 0.1;
		modifierBlocking = 1;
	};
	class RnCTS_rotateRight
	{
		displayName = "Rotate Right";
		tooltip = "Rotate Selected Objects Right to the Rotation Grid Increment.";
		onActivate = "";
		onDeactivate = "[6] spawn RnCTS_fnc_objectModifier";
		onAnalog = "";
		analogChangeThreshold = 0.1;
		modifierBlocking = 1;
	};
};
class UserActionGroups
{
	class ModSection
	{
		name = "R&C Terrain Suite";
		isAddon = 1;
		group[] = {"RnCTS_snap2Surface","RnCTS_orient2Sea","RnCTS_orient2Ground","RnCTS_openAttributes","RnCTS_rotateRight","RnCTS_rotateLeft"};
	};
};
class CfgFunctions
{
	class RnCTS
	{
		tag = "RnCTS";
		class functions
		{
			file = "\RnCTS\functions";
			class exportHF{};
			class objectModifier{};
		};
	};
};
class RscPicture;
class RscText;
class RscProgress;
class RnCTS_ProgressBar
{
	show = 0;
	movingEnable = 0;
	idd = -1;
	onLoad = "uiNamespace setVariable [""RnCTS_ProgressBar_Display"", (_this select 0)];";
	onUnload = "uiNamespace setVariable [""RnCTS_ProgressBar_Display"", nil];";
	class ControlsBackground
	{
		class RnCTS_Select_Mainback: RscPicture
		{
			idc = -1;
			x = "0.2 * safezoneW + safezoneX";
			y = "0.302 * safezoneH + safezoneY";
			w = "0.6 * safezoneW";
			h = "0.02 * safezoneH";
			moving = 0;
			text = "#(argb,8,8,3)color(0,0,0,0.7)";
		};
	};
	class Controls
	{
		class RnCTS_ProgressBar_Text: RscText
		{
			idc = 34516;
			text = "";
			style = 2;
			x = "0.2 * safezoneW + safezoneX";
			y = "0.268 * safezoneH + safezoneY";
			w = "0.6 * safezoneW";
			h = "0.04 * safezoneH";
		};
		class RnCTS_ProgressBar_Bar: RscProgress
		{
			idc = 34517;
			text = "";
			x = "0.2 * safezoneW + safezoneX";
			y = "0.302 * safezoneH + safezoneY";
			w = "0.6 * safezoneW";
			h = "0.02 * safezoneH";
			colorFrame[] = {0,0,0,1};
		};
	};
};
class ctrlMenuStrip;
class display3DEN
{
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				class MissionExport
				{
					items[] += {"RNCExportHF"};
				};
				class RNCExportHF
				{
					text = "Export Heightfield";
					data = "RNCExportHF";
					action = "[] spawn RnCTS_fnc_exportHF;";
				};
			};
		};
	};
};
class Cfg3DEN
{
	class Notifications
	{
		class RnCTS_exportDone
		{
			text = "Heightfield Exported";
			isWarning = 0;
		};
		class RnCTS_snapped
		{
			text = "Objects Snapped to Ground";
			isWarning = 0;
		};
		class RnCTS_seaOriented
		{
			text = "Objects Oriented to Sea";
			isWarning = 0;
		};
		class RnCTS_groundOriented
		{
			text = "Objects Oriented to Ground";
			isWarning = 0;
		};
		class RnCTS_noObjectsSelected
		{
			text = "No Objects Selected";
			isWarning = 1;
		};
		class RnCTS_objectsRotatedLeft
		{
			text = "Objects Rotated Left";
			isWarning = 0;
		};
		class RnCTS_objectsRotatedRight
		{
			text = "Objects Rotated Right";
			isWarning = 0;
		};
	};
};
