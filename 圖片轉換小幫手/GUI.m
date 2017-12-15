function varargout = GUI(varargin)
% GUI MATLAB code for GUI.fig
%      GUI, by itself, creates a new GUI or raises the existing
%      singleton*.
%
%      H = GUI returns the handle to a new GUI or the handle to
%      the existing singleton*.
%
%      GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI.M with the given input arguments.
%
%      GUI('Property','Value',...) creates a new GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI

% Last Modified by GUIDE v2.5 07-Nov-2017 06:22:18

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI is made visible.
function GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI (see VARARGIN)

% Choose default command line output for GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in start.
function start_Callback(hObject, eventdata, handles)
% hObject    handle to start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Input = get(handles.InputText, 'String');
Output = get(handles.OutputText, 'String');

start = questdlg({'請確認以下路徑是否正確' '輸入資料夾' Input '輸出資料夾' Output},'開始執行','是','否','否');

if start == '是'
    h = waitbar(0,{'Please wait..' ' '});
    getAllFiles(Input, Output, h);
    close(h);
    h = msgbox('轉檔完成','轉檔');
end

% --- Executes on button press in Input.
function Input_Callback(hObject, eventdata, handles)
% hObject    handle to Input (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
filepath = uigetdir;
if filepath ~= 0
    set(handles.InputText, 'String', filepath);
end


% --- Executes on button press in Output.
function Output_Callback(hObject, eventdata, handles)
% hObject    handle to Output (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
filepath = uigetdir;
if filepath ~= 0
    set(handles.OutputText, 'String', filepath);
end


%getAllFiles('Source', 'Output');
function getAllFiles(inputDir, outputDir, h)
    types = ['.jpg';'.png';'.bmp'];
    types2 = ['jpeg'];
    if exist(outputDir) == 0                            % Make dir
        mkdir(outputDir);
    end
	dirData = dir(inputDir);                            % Get the data for the current directory
	dirIndex = [dirData.isdir];                         % Find the index for directories
	fileList = {dirData(~dirIndex).name};               % Get a list of the files
	if ~isempty(fileList)
        for file = fileList
            if ismember({lower(file{1}(length(file{1})-3:length(file{1})))}, types) || ...
                ismember({lower(file{1}(length(file{1})-4:length(file{1})))}, types2)
                %disp([outputDir '\' file{1}]);
                waitbar(0,h,{'Converting..' file{1}});
                x = imread([inputDir '\' file{1}]);
                y = rgb2gray(x);
                imwrite(y,[outputDir '\' file{1}]);
            end
        end
    end
  
	subDirs = {dirData(dirIndex).name};                 % Get a list of the subdirectories
	validIndex = ~ismember(subDirs,{'.','..'});         % Find index of subdirectories
                                                        %   that are not '.' or '..'
	for iDir = find(validIndex)                         % Loop over valid subdirectories
	nextInputDir = fullfile(inputDir,subDirs{iDir});    % Get the subdirectory path
    nextOutputDir = fullfile(outputDir,subDirs{iDir});
	getAllFiles(nextInputDir,nextOutputDir, h);            % Recursively call getAllFiles
    end
