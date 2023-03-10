getTerrainInfo params ["", "", "_cellsize", "_resolution"];

disableUserInput true;

_header = format ["ncols %1
nrows %1
xllcorner 200000.000000
yllcorner 0.000000
cellsize %2
NODATA_value -9999",_resolution, _cellsize];

// progress bar IDc
private _textId = 34516;
private _barId  = 34517;

// init
disableSerialization;

// create dialog
createDialog "DHE_ProgressBar";

// get controls
private _display = uiNamespace getVariable "DHE_ProgressBar_Display";
private _bar     = _display displayCtrl _barId;
private _barText = _display displayCtrl _textId;

"ConfigDumpFileIO" callExtension "open:hf.asc";

"ConfigDumpFileIO" callExtension ("write:"+_header);

_i = 0;
for "_y" from (_resolution - 1) to 0 step -1 do { 
	_line = []; 
	for "_x" from 0 to (_resolution - 1) do { 
		_line pushBack (getTerrainHeightASL [_x*_cellsize, _y*_cellsize]);
	};
	_lineStr = _line joinString " ";
	
	"ConfigDumpFileIO" callExtension ("write:"+_lineStr);
	
	_i = _i + 1;
	_barText ctrlSetText "Exporting Heightfield";
	_bar progressSetPosition (_i / _resolution);
}; 

"ConfigDumpFileIO" callExtension "close:yes";

disableUserInput false;
disableSerialization;
["DHE_exportDone", 5] call BIS_fnc_3DENNotification;
closeDialog 1;