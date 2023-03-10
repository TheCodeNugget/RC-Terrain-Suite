class CfgPatches
{
	class DHE
	{
		name="Deformer Heightfield Exporter";
		author="KenTheNugget";
		units[]={};
		weapons[]={};
		requiredVersion=1;
		requiredAddons[]= {
			"3den"
		};
		fileName="DHE.pbo";
	};
};

class CfgFunctions {
	class DHE {
		tag="DHE";
		class functions {
			file="\DHE\functions";
			class exportHF {};
		};
	};
};

class RscPicture;
class RscText;
class RscProgress;
class DHE_ProgressBar {
	show=0;
	movingEnable=0;
	idd=-1;
	onLoad="uiNamespace setVariable [""DHE_ProgressBar_Display"", (_this select 0)];";
	onUnload="uiNamespace setVariable [""DHE_ProgressBar_Display"", nil];";
	class ControlsBackground
	{
		class DHE_Select_Mainback: RscPicture
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
		class DHE_ProgressBar_Text: RscText
		{
			idc=34516;
			text="";
			style=2;
			x="0.2 * safezoneW + safezoneX";
			y="0.268 * safezoneH + safezoneY";
			w="0.6 * safezoneW";
			h="0.04 * safezoneH";
		};
		class DHE_ProgressBar_Bar: RscProgress
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
						"DHEExportHF",
					};
				};
				class DHEExportHF {
					text="Export Heightfield";
					data="E2TBMissionTerrainBuilder";
					action="[] spawn DHE_fnc_exportHF;";
				};
			};
		};
	};
};

class Cfg3DEN {
	class Notifications {
		class DHE_exportDone {
			text="Heightfield Exported";
			isWarning=0;
		};
	};
};
