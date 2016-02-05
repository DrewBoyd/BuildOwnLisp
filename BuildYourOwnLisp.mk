##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=BuildYourOwnLisp
ConfigurationName      :=Debug
WorkspacePath          := "/home/andrew-boyd/d/buildownlisp2"
ProjectPath            := "/home/andrew-boyd/d/buildownlisp2"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Andrew
Date                   :=01/29/16
CodeLitePath           :="/home/andrew-boyd/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="BuildYourOwnLisp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -ledit -lm
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -std=c99 $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/builtin.c$(ObjectSuffix) $(IntermediateDirectory)/lenv.c$(ObjectSuffix) $(IntermediateDirectory)/lval.c$(ObjectSuffix) $(IntermediateDirectory)/mpc.c$(ObjectSuffix) $(IntermediateDirectory)/prompt.c$(ObjectSuffix) $(IntermediateDirectory)/repl.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/builtin.c$(ObjectSuffix): builtin.c $(IntermediateDirectory)/builtin.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/andrew-boyd/d/buildownlisp2/builtin.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/builtin.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/builtin.c$(DependSuffix): builtin.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/builtin.c$(ObjectSuffix) -MF$(IntermediateDirectory)/builtin.c$(DependSuffix) -MM "builtin.c"

$(IntermediateDirectory)/builtin.c$(PreprocessSuffix): builtin.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/builtin.c$(PreprocessSuffix) "builtin.c"

$(IntermediateDirectory)/lenv.c$(ObjectSuffix): lenv.c $(IntermediateDirectory)/lenv.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/andrew-boyd/d/buildownlisp2/lenv.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lenv.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lenv.c$(DependSuffix): lenv.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lenv.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lenv.c$(DependSuffix) -MM "lenv.c"

$(IntermediateDirectory)/lenv.c$(PreprocessSuffix): lenv.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lenv.c$(PreprocessSuffix) "lenv.c"

$(IntermediateDirectory)/lval.c$(ObjectSuffix): lval.c $(IntermediateDirectory)/lval.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/andrew-boyd/d/buildownlisp2/lval.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lval.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lval.c$(DependSuffix): lval.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lval.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lval.c$(DependSuffix) -MM "lval.c"

$(IntermediateDirectory)/lval.c$(PreprocessSuffix): lval.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lval.c$(PreprocessSuffix) "lval.c"

$(IntermediateDirectory)/mpc.c$(ObjectSuffix): mpc.c $(IntermediateDirectory)/mpc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/andrew-boyd/d/buildownlisp2/mpc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mpc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mpc.c$(DependSuffix): mpc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mpc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mpc.c$(DependSuffix) -MM "mpc.c"

$(IntermediateDirectory)/mpc.c$(PreprocessSuffix): mpc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mpc.c$(PreprocessSuffix) "mpc.c"

$(IntermediateDirectory)/prompt.c$(ObjectSuffix): prompt.c $(IntermediateDirectory)/prompt.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/andrew-boyd/d/buildownlisp2/prompt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/prompt.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/prompt.c$(DependSuffix): prompt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/prompt.c$(ObjectSuffix) -MF$(IntermediateDirectory)/prompt.c$(DependSuffix) -MM "prompt.c"

$(IntermediateDirectory)/prompt.c$(PreprocessSuffix): prompt.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/prompt.c$(PreprocessSuffix) "prompt.c"

$(IntermediateDirectory)/repl.c$(ObjectSuffix): repl.c $(IntermediateDirectory)/repl.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/andrew-boyd/d/buildownlisp2/repl.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/repl.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/repl.c$(DependSuffix): repl.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/repl.c$(ObjectSuffix) -MF$(IntermediateDirectory)/repl.c$(DependSuffix) -MM "repl.c"

$(IntermediateDirectory)/repl.c$(PreprocessSuffix): repl.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/repl.c$(PreprocessSuffix) "repl.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/BuildYourOwnLisp"


