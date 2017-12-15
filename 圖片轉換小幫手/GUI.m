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

% Last Modified by GUIDE v2.5 23-Nov-2017 02:46:52

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

set(handles.InputText, 'String', fullfile(pwd,'input'));
set(handles.OutputText, 'String', fullfile(pwd,'output'));


%set(handles.InputText, 'String', fullfile(pwd,'input'));
%set(handles.OutputText, 'String', fullfile(pwd,'output'));

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
    getAllFiles(Input, Output, h, get(handles.Grayscale, 'value'), get(handles.Image_size, 'value')...
        , [str2num(get(handles.Image_size_height, 'String')) str2num(get(handles.Image_size_width, 'String'))]...
        , get(handles.cropbutton, 'value'));
    close(h);
    h = msgbox('轉檔完成!','轉檔');
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

% --- Executes on button press in Grayscale.
function Grayscale_Callback(hObject, eventdata, handles)
% hObject    handle to Grayscale (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Grayscale


% --- Executes on button press in Image_size.
function Image_size_Callback(hObject, eventdata, handles)
% hObject    handle to Image_size (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Image_size
if get(handles.Image_size, 'value') == 0
    set(handles.cropbutton, 'enable', 'off');
    set(handles.Image_size_width, 'enable', 'off');
    set(handles.Image_size_height, 'enable', 'off');
    set(handles.sizepanel, 'foregroundcolor', [0.502 0.502 0.502]);
    set(handles.cropbutton, 'foregroundcolor', [0.502 0.502 0.502]);
    set(handles.widthText, 'foregroundcolor', [0.502 0.502 0.502]);
    set(handles.heightText, 'foregroundcolor', [0.502 0.502 0.502]);
else
    set(handles.sizepanel, 'foregroundcolor', [0 0 0]);
    set(handles.cropbutton, 'enable', 'on');
    set(handles.Image_size_width, 'enable', 'on');
    set(handles.Image_size_height, 'enable', 'on');
    set(handles.sizepanel, 'foregroundcolor', [0 0 0]);
    set(handles.cropbutton, 'foregroundcolor', [0 0 0]);
    set(handles.widthText, 'foregroundcolor', [0 0 0]);
    set(handles.heightText, 'foregroundcolor', [0 0 0]);
end


function Image_size_width_Callback(hObject, eventdata, handles)
% hObject    handle to Image_size_width (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Image_size_width as text
%        str2double(get(hObject,'String')) returns contents of Image_size_width as a double
str=get(hObject,'String');
if isempty(str2num(str))
    set(hObject,'string','0');
    warndlg('Input must be numerical');
end

% --- Executes during object creation, after setting all properties.
function Image_size_width_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Image_size_width (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function Image_size_height_Callback(hObject, eventdata, handles)
% hObject    handle to Image_size_height (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Image_size_height as text
%        str2double(get(hObject,'String')) returns contents of Image_size_height as a double
str=get(hObject,'String');
if isempty(str2num(str))
    set(hObject,'string','0');
    warndlg('Image size must be numerical');
end


% --- Executes during object creation, after setting all properties.
function Image_size_height_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Image_size_height (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on key press with focus on Image_size_width and none of its controls.
function Image_size_width_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to Image_size_width (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)
str=get(hObject,'String');
if isempty(str2num(str))
    set(hObject,'string','0');
    warndlg('Image size must be numerical');
end


% --- Executes on button press in cropbutton.
function cropbutton_Callback(hObject, eventdata, handles)
% hObject    handle to cropbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cropbutton


%getAllFiles('Source', 'Output');
function getAllFiles(inputDir, outputDir, h, doGrayscale, doImage_size, imageSize, doCrop)
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
                
                if doImage_size == 1
                    if doCrop == 1                      % Crop image
                        factor_width = size(x,1)*imageSize(2)/imageSize(1);
                        factor_height = size(x,2)*imageSize(1)/imageSize(2);
                        if size(x,1) > factor_height
                            x = imcrop(x, [1,(size(x,1)-factor_height)/2,size(x,2),factor_height]);
                        else
                            x = imcrop(x, [(size(x,2)-factor_width)/2,1,factor_width,size(x,1)]);
                            disp(num2str((size(x,2)-factor_width)/2 + factor_width - (size(x,2)-factor_width)/2));
                        end
                    end
                    x = imresize(x, imageSize);         % Resize image
                end
                
                if doGrayscale == 1 && size(x,3) == 3
                    x = rgb2gray(x);                    % Grayscale transform
                end
                
                imwrite(x,[outputDir '\' file{1}]);
            end
        end
    end
  
	subDirs = {dirData(dirIndex).name};                 % Get a list of the subdirectories
	validIndex = ~ismember(subDirs,{'.','..'});         % Find index of subdirectories
                                                        %   that are not '.' or '..'
	for iDir = find(validIndex)                         % Loop over valid subdirectories
	nextInputDir = fullfile(inputDir,subDirs{iDir});    % Get the subdirectory path
    nextOutputDir = fullfile(outputDir,subDirs{iDir});
	getAllFiles(nextInputDir,nextOutputDir, h, doGrayscale, doImage_size, imageSize, doCrop);   % Recursively call getAllFiles
    end
