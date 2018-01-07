﻿// -----------------------------------------------------------------------------------------
// NVEnc by rigaya
// -----------------------------------------------------------------------------------------
// The MIT License
//
// Copyright (c) 2014-2016 rigaya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// ------------------------------------------------------------------------------------------

#pragma once

#include <Windows.h>

#include "auo.h"
#include "auo_pipe.h"
#include "auo_conf.h"
#include "auo_settings.h"
#include "auo_system.h"
#include "auo_util.h"
#include "auo_clrutil.h"

#include "frmConfig_helper.h"

#include "NVEncParam.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


namespace NVEnc {

    /// <summary>
    /// frmConfig の概要
    ///
    /// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
    ///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
    ///          変更する必要があります。この変更を行わないと、
    ///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
    ///          正しく相互に利用できなくなります。
    /// </summary>
    public ref class frmConfig : public System::Windows::Forms::Form
    {
    public:
        frmConfig(CONF_GUIEX *_conf, const SYSTEM_DATA *_sys_dat)
        {
            try {
                featureCache = nvfeature_create();
            } catch (...) {
                ;
            }
            if (featureCache)
                nvfeature_createCacheAsync(featureCache, 0);
            InitData(_conf, _sys_dat);
            cnf_stgSelected = (CONF_GUIEX *)calloc(1, sizeof(CONF_GUIEX));
            InitializeComponent();
            //
            //TODO: ここにコンストラクタ コードを追加します
            //
        }

    protected:
        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        ~frmConfig()
        {
            if (featureCache) {
                nvfeature_close(featureCache);
                featureCache = nullptr;
            }
            if (components)
            {
                delete components;
            }
            CloseBitrateCalc();
            if (cnf_stgSelected) free(cnf_stgSelected); cnf_stgSelected = NULL;
        }




    private: System::Windows::Forms::ToolStrip^  fcgtoolStripSettings;

    private: System::Windows::Forms::TabControl^  fcgtabControlMux;
    private: System::Windows::Forms::TabPage^  fcgtabPageMP4;
    private: System::Windows::Forms::TabPage^  fcgtabPageMKV;
    private: System::Windows::Forms::TextBox^  fcgTXCmd;

    private: System::Windows::Forms::Button^  fcgBTCancel;

    private: System::Windows::Forms::Button^  fcgBTOK;
    private: System::Windows::Forms::Button^  fcgBTDefault;




    private: System::Windows::Forms::ToolStripButton^  fcgTSBSave;

    private: System::Windows::Forms::ToolStripButton^  fcgTSBSaveNew;

    private: System::Windows::Forms::ToolStripButton^  fcgTSBDelete;

    private: System::Windows::Forms::ToolStripSeparator^  fcgtoolStripSeparator1;
    private: System::Windows::Forms::ToolStripDropDownButton^  fcgTSSettings;





























































































































































































































































    private: System::Windows::Forms::TabPage^  fcgtabPageMux;












    private: System::Windows::Forms::ComboBox^  fcgCXMP4CmdEx;

    private: System::Windows::Forms::Label^  fcgLBMP4CmdEx;
    private: System::Windows::Forms::CheckBox^  fcgCBMP4MuxerExt;
    private: System::Windows::Forms::Button^  fcgBTMP4BoxTempDir;
    private: System::Windows::Forms::TextBox^  fcgTXMP4BoxTempDir;


    private: System::Windows::Forms::ComboBox^  fcgCXMP4BoxTempDir;
    private: System::Windows::Forms::Label^  fcgLBMP4BoxTempDir;
    private: System::Windows::Forms::Button^  fcgBTTC2MP4Path;
    private: System::Windows::Forms::TextBox^  fcgTXTC2MP4Path;
    private: System::Windows::Forms::Button^  fcgBTMP4MuxerPath;
    private: System::Windows::Forms::TextBox^  fcgTXMP4MuxerPath;

    private: System::Windows::Forms::Label^  fcgLBTC2MP4Path;
    private: System::Windows::Forms::Label^  fcgLBMP4MuxerPath;


    private: System::Windows::Forms::Button^  fcgBTMKVMuxerPath;

    private: System::Windows::Forms::TextBox^  fcgTXMKVMuxerPath;

    private: System::Windows::Forms::Label^  fcgLBMKVMuxerPath;
    private: System::Windows::Forms::ComboBox^  fcgCXMKVCmdEx;
    private: System::Windows::Forms::Label^  fcgLBMKVMuxerCmdEx;
    private: System::Windows::Forms::CheckBox^  fcgCBMKVMuxerExt;
    private: System::Windows::Forms::ComboBox^  fcgCXMuxPriority;
    private: System::Windows::Forms::Label^  fcgLBMuxPriority;
    private: System::Windows::Forms::CheckBox^  fcgCBMuxMinimize;
    private: System::Windows::Forms::Label^  fcgLBVersionDate;


    private: System::Windows::Forms::Label^  fcgLBVersion;
    private: System::Windows::Forms::FolderBrowserDialog^  fcgfolderBrowserTemp;
    private: System::Windows::Forms::OpenFileDialog^  fcgOpenFileDialog;










private: System::Windows::Forms::ToolTip^  fcgTTEx;






private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
private: System::Windows::Forms::ToolStripButton^  fcgTSBOtherSettings;















































































































private: System::Windows::Forms::ToolStripButton^  fcgTSBBitrateCalc;
private: System::Windows::Forms::TabControl^  fcgtabControlNVEnc;

private: System::Windows::Forms::TabPage^  tabPageVideoEnc;












private: System::Windows::Forms::GroupBox^  fcgGroupBoxAspectRatio;
private: System::Windows::Forms::Label^  fcgLBAspectRatio;
private: System::Windows::Forms::NumericUpDown^  fcgNUAspectRatioY;
private: System::Windows::Forms::NumericUpDown^  fcgNUAspectRatioX;
private: System::Windows::Forms::ComboBox^  fcgCXAspectRatio;
private: System::Windows::Forms::ComboBox^  fcgCXInterlaced;
private: System::Windows::Forms::Label^  fcgLBInterlaced;
private: System::Windows::Forms::NumericUpDown^  fcgNUGopLength;
private: System::Windows::Forms::Label^  fcgLBGOPLength;
private: System::Windows::Forms::ComboBox^  fcgCXCodecLevel;
private: System::Windows::Forms::ComboBox^  fcgCXCodecProfile;
private: System::Windows::Forms::Label^  fcgLBCodecLevel;
private: System::Windows::Forms::Label^  fcgLBCodecProfile;




private: System::Windows::Forms::Label^  fcgLBMaxBitrate2;
private: System::Windows::Forms::Label^  fcgLBEncMode;
private: System::Windows::Forms::ComboBox^  fcgCXEncMode;
private: System::Windows::Forms::Label^  fcgLBMaxkbps;
private: System::Windows::Forms::NumericUpDown^  fcgNUMaxkbps;
private: System::Windows::Forms::Label^  fcgLBQPB;
private: System::Windows::Forms::Label^  fcgLBQPP;
private: System::Windows::Forms::Label^  fcgLBQPI;

private: System::Windows::Forms::NumericUpDown^  fcgNUQPB;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPP;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPI;



private: System::Windows::Forms::Label^  fcgLBBitrate2;
private: System::Windows::Forms::NumericUpDown^  fcgNUBitrate;
private: System::Windows::Forms::Label^  fcgLBBitrate;

























private: System::Windows::Forms::TabPage^  tabPageExOpt;








private: System::Windows::Forms::Label^  fcgLBGOPLengthAuto;


































private: System::Windows::Forms::ToolStripLabel^  fcgTSLSettingsNotes;
private: System::Windows::Forms::ToolStripTextBox^  fcgTSTSettingsNotes;
private: System::Windows::Forms::TabPage^  fcgtabPageBat;
private: System::Windows::Forms::Button^  fcgBTBatAfterPath;

private: System::Windows::Forms::TextBox^  fcgTXBatAfterPath;

private: System::Windows::Forms::Label^  fcgLBBatAfterPath;

private: System::Windows::Forms::CheckBox^  fcgCBWaitForBatAfter;

private: System::Windows::Forms::CheckBox^  fcgCBRunBatAfter;

private: System::Windows::Forms::CheckBox^  fcgCBMP4MuxApple;











private: System::Windows::Forms::Panel^  fcgPNBitrate;
private: System::Windows::Forms::Panel^  fcgPNQP;













private: System::Windows::Forms::Button^  fcgBTMP4RawPath;

private: System::Windows::Forms::TextBox^  fcgTXMP4RawPath;
private: System::Windows::Forms::Label^  fcgLBMP4RawPath;





private: System::Windows::Forms::TabPage^  fcgtabPageMPG;
private: System::Windows::Forms::Button^  fcgBTMPGMuxerPath;

private: System::Windows::Forms::TextBox^  fcgTXMPGMuxerPath;

private: System::Windows::Forms::Label^  fcgLBMPGMuxerPath;

private: System::Windows::Forms::ComboBox^  fcgCXMPGCmdEx;
private: System::Windows::Forms::Label^  fcgLBMPGMuxerCmdEx;


private: System::Windows::Forms::CheckBox^  fcgCBMPGMuxerExt;

private: System::Windows::Forms::ContextMenuStrip^  fcgCSExeFiles;
private: System::Windows::Forms::ToolStripMenuItem^  fcgTSExeFileshelp;




private: System::Windows::Forms::Label^  fcgLBBatAfterString;

private: System::Windows::Forms::Label^  fcgLBBatBeforeString;
private: System::Windows::Forms::Panel^  fcgPNSeparator;
private: System::Windows::Forms::Button^  fcgBTBatBeforePath;
private: System::Windows::Forms::TextBox^  fcgTXBatBeforePath;
private: System::Windows::Forms::Label^  fcgLBBatBeforePath;
private: System::Windows::Forms::CheckBox^  fcgCBWaitForBatBefore;
private: System::Windows::Forms::CheckBox^  fcgCBRunBatBefore;
private: System::Windows::Forms::LinkLabel^  fcgLBguiExBlog;







































private: System::Windows::Forms::NumericUpDown^  fcgNUBframes;
private: System::Windows::Forms::Label^  fcgLBBframes;


private: System::Windows::Forms::Label^  fcgLBFullrangeH264;
private: System::Windows::Forms::CheckBox^  fcgCBFullrangeH264;
private: System::Windows::Forms::ComboBox^  fcgCXVideoFormatH264;
private: System::Windows::Forms::Label^  fcgLBVideoFormatH264;
private: System::Windows::Forms::GroupBox^  fcggroupBoxColorH264;
private: System::Windows::Forms::ComboBox^  fcgCXTransferH264;
private: System::Windows::Forms::ComboBox^  fcgCXColorPrimH264;
private: System::Windows::Forms::ComboBox^  fcgCXColorMatrixH264;
private: System::Windows::Forms::Label^  fcgLBTransferH264;
private: System::Windows::Forms::Label^  fcgLBColorPrimH264;
private: System::Windows::Forms::Label^  fcgLBColorMatrixH264;
private: System::Windows::Forms::NumericUpDown^  fcgNURefFrames;
private: System::Windows::Forms::Label^  fcgLBRefFrames;




private: System::Windows::Forms::TabPage^  tabPageNVEncFeatures;
private: System::Windows::Forms::DataGridView^  fcgDGVFeaturesH264;

private: System::Windows::Forms::Label^  fcgLBOSInfo;
private: System::Windows::Forms::Label^  fcgLBOSInfoLabel;
private: System::Windows::Forms::Label^  fcgLBCPUInfoOnFeatureTab;
private: System::Windows::Forms::Label^  fcgLBCPUInfoLabelOnFeatureTab;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  fcgLBGPUInfoOnFeatureTab;
private: System::Windows::Forms::Label^  fcgLBGPUInfoLabelOnFeatureTab;
private: System::Windows::Forms::PictureBox^  fcgPBNVEncLogoEnabled;

private: System::Windows::Forms::PictureBox^  fcgPBNVEncLogoDisabled;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::ComboBox^  fcgCXEncCodec;
private: System::Windows::Forms::Panel^  fcgPNH264;


private: System::Windows::Forms::Panel^  fcgPNHEVC;


private: System::Windows::Forms::Label^  fcgLBHEVCProfile;
private: System::Windows::Forms::Label^  fxgLBHEVCTier;
private: System::Windows::Forms::ComboBox^  fcgCXHEVCTier;





private: System::Windows::Forms::ComboBox^  fxgCXHEVCLevel;























private: System::Windows::Forms::TabControl^  fcgTabControlFeatures;
private: System::Windows::Forms::TabPage^  fcgTabPageH264;
private: System::Windows::Forms::TabPage^  fcgTabPageHEVC;
private: System::Windows::Forms::DataGridView^  fcgDGVFeaturesHEVC;
private: System::Windows::Forms::CheckBox^  fcgCBAFS;
private: System::Windows::Forms::NumericUpDown^  fcgNUVBVBufsize;
private: System::Windows::Forms::Label^  fcgLBVBVBufsize;
private: System::Windows::Forms::Label^  fcgLBBluray;
private: System::Windows::Forms::CheckBox^  fcgCBBluray;
private: System::Windows::Forms::TabControl^  fcgtabControlAudio;
private: System::Windows::Forms::TabPage^  fcgtabPageAudioMain;
private: System::Windows::Forms::ComboBox^  fcgCXAudioDelayCut;
private: System::Windows::Forms::Label^  fcgLBAudioDelayCut;
private: System::Windows::Forms::Label^  fcgCBAudioEncTiming;
private: System::Windows::Forms::ComboBox^  fcgCXAudioEncTiming;
private: System::Windows::Forms::ComboBox^  fcgCXAudioTempDir;
private: System::Windows::Forms::TextBox^  fcgTXCustomAudioTempDir;
private: System::Windows::Forms::Button^  fcgBTCustomAudioTempDir;
private: System::Windows::Forms::CheckBox^  fcgCBAudioUsePipe;
private: System::Windows::Forms::Label^  fcgLBAudioBitrate;
private: System::Windows::Forms::NumericUpDown^  fcgNUAudioBitrate;
private: System::Windows::Forms::CheckBox^  fcgCBAudio2pass;
private: System::Windows::Forms::ComboBox^  fcgCXAudioEncMode;
private: System::Windows::Forms::Label^  fcgLBAudioEncMode;
private: System::Windows::Forms::Button^  fcgBTAudioEncoderPath;
private: System::Windows::Forms::TextBox^  fcgTXAudioEncoderPath;
private: System::Windows::Forms::Label^  fcgLBAudioEncoderPath;
private: System::Windows::Forms::CheckBox^  fcgCBAudioOnly;
private: System::Windows::Forms::CheckBox^  fcgCBFAWCheck;
private: System::Windows::Forms::ComboBox^  fcgCXAudioEncoder;
private: System::Windows::Forms::Label^  fcgLBAudioEncoder;
private: System::Windows::Forms::Label^  fcgLBAudioTemp;
private: System::Windows::Forms::TabPage^  fcgtabPageAudioOther;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::Label^  fcgLBBatAfterAudioString;
private: System::Windows::Forms::Label^  fcgLBBatBeforeAudioString;
private: System::Windows::Forms::Button^  fcgBTBatAfterAudioPath;
private: System::Windows::Forms::TextBox^  fcgTXBatAfterAudioPath;
private: System::Windows::Forms::Label^  fcgLBBatAfterAudioPath;
private: System::Windows::Forms::CheckBox^  fcgCBRunBatAfterAudio;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Button^  fcgBTBatBeforeAudioPath;
private: System::Windows::Forms::TextBox^  fcgTXBatBeforeAudioPath;
private: System::Windows::Forms::Label^  fcgLBBatBeforeAudioPath;
private: System::Windows::Forms::CheckBox^  fcgCBRunBatBeforeAudio;
private: System::Windows::Forms::ComboBox^  fcgCXAudioPriority;
private: System::Windows::Forms::Label^  fcgLBAudioPriority;

private: System::Windows::Forms::Label^  fcgLBAQ;
private: System::Windows::Forms::Label^  fcgLBFullrangeHEVC;
private: System::Windows::Forms::CheckBox^  fcgCBFullrangeHEVC;


private: System::Windows::Forms::ComboBox^  fcgCXVideoFormatHEVC;

private: System::Windows::Forms::Label^  fcgLBVideoFormatHEVC;
private: System::Windows::Forms::GroupBox^  fcggroupBoxColorHEVC;
private: System::Windows::Forms::ComboBox^  fcgCXTransferHEVC;
private: System::Windows::Forms::ComboBox^  fcgCXColorPrimHEVC;
private: System::Windows::Forms::ComboBox^  fcgCXColorMatrixHEVC;
private: System::Windows::Forms::Label^  fcgLBTransferHEVC;
private: System::Windows::Forms::Label^  fcgLBColorPrimHEVC;
private: System::Windows::Forms::Label^  fcgLBColorMatrixHEVC;
private: System::Windows::Forms::Label^  fcgLBLookaheadDisable;
private: System::Windows::Forms::NumericUpDown^  fcgNULookaheadDepth;

private: System::Windows::Forms::Label^  fcgLBAQStrengthAuto;
private: System::Windows::Forms::NumericUpDown^  fcgNUAQStrength;
private: System::Windows::Forms::Label^  fcgLBAQStrength;
private: System::Windows::Forms::ComboBox^  fcgCXAQ;

private: System::Windows::Forms::Label^  fcgLBLookaheadDepth;
private: System::Windows::Forms::Label^  fcgLBHEVCOutBitDepth;
private: System::Windows::Forms::ComboBox^  fcgCXHEVCOutBitDepth;





























private: System::Windows::Forms::TabPage^  tabPageVideoDetail;
private: System::Windows::Forms::Label^  fcgLBSlices;

private: System::Windows::Forms::NumericUpDown^  fcgNUSlices;

private: System::Windows::Forms::Panel^  fcgPNH264Detail;
private: System::Windows::Forms::Label^  fcgLBDeblock;


private: System::Windows::Forms::ComboBox^  fcgCXAdaptiveTransform;
private: System::Windows::Forms::Label^  fcgLBAdaptiveTransform;
private: System::Windows::Forms::ComboBox^  fcgCXBDirectMode;
private: System::Windows::Forms::Label^  fcgLBBDirectMode;
private: System::Windows::Forms::Label^  fcgLBMVPrecision;





private: System::Windows::Forms::ComboBox^  fcgCXMVPrecision;
private: System::Windows::Forms::CheckBox^  fcgCBDeblock;


private: System::Windows::Forms::CheckBox^  fcgCBCABAC;
private: System::Windows::Forms::Label^  fcgLBCABAC;


private: System::Windows::Forms::Panel^  fcgPNHEVCDetail;
private: System::Windows::Forms::Label^  fcgLBHEVCMinCUSize;


private: System::Windows::Forms::ComboBox^  fcgCXHEVCMinCUSize;
private: System::Windows::Forms::Label^  fcgLBHEVCMaxCUSize;


private: System::Windows::Forms::ComboBox^  fcgCXHEVCMaxCUSize;

private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  fcgLBDevice;

private: System::Windows::Forms::ComboBox^  fcgCXDevice;
private: System::Windows::Forms::GroupBox^  groupBoxQPDetail;
private: System::Windows::Forms::Label^  fcgLBQPDetailB;
private: System::Windows::Forms::Label^  fcgLBQPDetailP;
private: System::Windows::Forms::Label^  fcgLBQPDetailI;
private: System::Windows::Forms::CheckBox^  fcgCBQPInit;

private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPInitB;

private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPInitP;

private: System::Windows::Forms::NumericUpDown^  fcgNUQPInitI;

private: System::Windows::Forms::CheckBox^  fcgCBQPMin;

private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPMinB;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPMinP;

private: System::Windows::Forms::NumericUpDown^  fcgNUQPMinI;

private: System::Windows::Forms::CheckBox^  fcgCBQPMax;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPMaxB;

private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPMaxP;

private: System::Windows::Forms::NumericUpDown^  fcgNUQPMaxI;
private: System::Windows::Forms::Label^  fcgLBWeightP;
private: System::Windows::Forms::CheckBox^  fcgCBWeightP;
private: System::Windows::Forms::GroupBox^  fcgGroupBoxQulaityStg;
private: System::Windows::Forms::Button^  fcgBTQualityStg;
private: System::Windows::Forms::ComboBox^  fcgCXQualityPreset;
private: System::Windows::Forms::NumericUpDown^  fcgNUVBRTragetQuality;
private: System::Windows::Forms::Label^  fcgLBVBRTragetQuality;
private: System::Windows::Forms::Label^  fcgLBVBRTragetQuality2;








































private: System::Windows::Forms::Label^  fcgLBCudaSchdule;
private: System::Windows::Forms::ComboBox^  fcgCXCudaSchdule;
private: System::Windows::Forms::CheckBox^  fcgCBPerfMonitor;

























































private: System::Windows::Forms::CheckBox^  fcgCBAuoTcfileout;

private: System::Windows::Forms::Label^  fcgLBTempDir;
private: System::Windows::Forms::Button^  fcgBTCustomTempDir;
private: System::Windows::Forms::TextBox^  fcgTXCustomTempDir;
private: System::Windows::Forms::ComboBox^  fcgCXTempDir;
private: System::Windows::Forms::GroupBox^  fcggroupBoxVppDetailEnahance;

private: System::Windows::Forms::Panel^  fcgPNVppUnsharp;
private: System::Windows::Forms::Label^  fcgLBVppUnsharpThreshold;
private: System::Windows::Forms::Label^  fcgLBVppUnsharpWeight;
private: System::Windows::Forms::Label^  fcgLBVppUnsharpRadius;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppUnsharpThreshold;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppUnsharpWeight;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppUnsharpRadius;
private: System::Windows::Forms::Panel^  fcgPNVppEdgelevel;

private: System::Windows::Forms::Label^  label10;


private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
private: System::Windows::Forms::ComboBox^  fcgCXVppDetailEnhance;
private: System::Windows::Forms::CheckBox^  fcgCBVppAfsEnable;




private: System::Windows::Forms::GroupBox^  fcggroupBoxVppAfs;
private: System::Windows::Forms::TrackBar^  fcgTBVppAfsThreCMotion;
private: System::Windows::Forms::Label^  fcgLBVppAfsThreCMotion;
private: System::Windows::Forms::TrackBar^  fcgTBVppAfsThreYMotion;
private: System::Windows::Forms::Label^  fcgLBVppAfsThreYmotion;
private: System::Windows::Forms::TrackBar^  fcgTBVppAfsThreDeint;
private: System::Windows::Forms::Label^  fcgLBVppAfsThreDeint;
private: System::Windows::Forms::TrackBar^  fcgTBVppAfsThreShift;
private: System::Windows::Forms::Label^  fcgLBVppAfsThreShift;
private: System::Windows::Forms::TrackBar^  fcgTBVppAfsCoeffShift;
private: System::Windows::Forms::Label^  fcgLBVppAfsCoeffShift;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  fcgLBVppAfsUp;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsRight;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsLeft;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsBottom;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsUp;
private: System::Windows::Forms::TrackBar^  fcgTBVppAfsMethodSwitch;
private: System::Windows::Forms::CheckBox^  fcgCBVppAfs24fps;
private: System::Windows::Forms::CheckBox^  fcgCBVppAfsTune;
private: System::Windows::Forms::CheckBox^  fcgCBVppAfsSmooth;
private: System::Windows::Forms::CheckBox^  fcgCBVppAfsDrop;
private: System::Windows::Forms::CheckBox^  fcgCBVppAfsShift;
private: System::Windows::Forms::Label^  fcgLBVppAfsAnalyze;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsThreCMotion;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsThreShift;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsThreDeint;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsThreYMotion;
private: System::Windows::Forms::Label^  fcgLBVppAfsMethodSwitch;
private: System::Windows::Forms::ComboBox^  fcgCXVppAfsAnalyze;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsCoeffShift;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppAfsMethodSwitch;
private: System::Windows::Forms::CheckBox^  fcgCBVppDebandEnable;
private: System::Windows::Forms::GroupBox^  fcggroupBoxVppDeband;
private: System::Windows::Forms::CheckBox^  fcgCBVppDebandRandEachFrame;
private: System::Windows::Forms::CheckBox^  fcgCBVppDebandBlurFirst;
private: System::Windows::Forms::Label^  fcgLBVppDebandSample;
private: System::Windows::Forms::Label^  fcgLBVppDebandDitherC;
private: System::Windows::Forms::Label^  fcgLBVppDebandDitherY;
private: System::Windows::Forms::Label^  fcgLBVppDebandDither;
private: System::Windows::Forms::Label^  fcgLBVppDebandThreCr;
private: System::Windows::Forms::Label^  fcgLBVppDebandThreCb;
private: System::Windows::Forms::Label^  fcgLBVppDebandThreY;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDebandDitherC;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDebandDitherY;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDebandThreCr;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDebandThreCb;
private: System::Windows::Forms::Label^  fcgLBVppDebandThreshold;
private: System::Windows::Forms::Label^  fcgLBVppDebandRange;
private: System::Windows::Forms::ComboBox^  fcgCXVppDebandSample;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDebandThreY;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDebandRange;
private: System::Windows::Forms::GroupBox^  fcggroupBoxVppDenoise;
private: System::Windows::Forms::Panel^  fcgPNVppDenoiseKnn;
private: System::Windows::Forms::Label^  fcgLBVppDenoiseKnnThreshold;
private: System::Windows::Forms::Label^  fcgLBVppDenoiseKnnStrength;
private: System::Windows::Forms::Label^  fcgLBVppDenoiseKnnRadius;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoiseKnnThreshold;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoiseKnnStrength;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoiseKnnRadius;
private: System::Windows::Forms::Panel^  fcgPNVppDenoisePmd;
private: System::Windows::Forms::Label^  fcgLBVppDenoisePmdThreshold;
private: System::Windows::Forms::Label^  fcgLBVppDenoisePmdStrength;
private: System::Windows::Forms::Label^  fcgLBVppDenoisePmdApplyCount;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoisePmdThreshold;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoisePmdStrength;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoisePmdApplyCount;
private: System::Windows::Forms::ComboBox^  fcgCXVppDenoiseMethod;
private: System::Windows::Forms::CheckBox^  fcgCBVppResize;
private: System::Windows::Forms::GroupBox^  fcggroupBoxResize;
private: System::Windows::Forms::ComboBox^  fcgCXVppResizeAlg;
private: System::Windows::Forms::Label^  fcgLBVppResize;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppResizeHeight;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppResizeWidth;
private: System::Windows::Forms::Label^  fcgLBVppEdgelevelThreshold;
private: System::Windows::Forms::Label^  fcgLBVppEdgelevelBlack;


private: System::Windows::Forms::Label^  fcgLBVppEdgelevelStrength;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppEdgelevelThreshold;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppEdgelevelBlack;




private: System::Windows::Forms::NumericUpDown^  fcgNUVppEdgelevelStrength;
private: System::Windows::Forms::Label^  fcgLBVppEdgelevelWhite;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppEdgelevelWhite;
private: System::Windows::Forms::CheckBox^  fcgCBVppPerfMonitor;
private: System::Windows::Forms::CheckBox^  fcgCBVppTweakEnable;
private: System::Windows::Forms::GroupBox^  fcggroupBoxVppTweak;


private: System::Windows::Forms::TrackBar^  fcgTBVppTweakHue;
private: System::Windows::Forms::Label^  fcgLBVppTweakHue;
private: System::Windows::Forms::TrackBar^  fcgTBVppTweakSaturation;
private: System::Windows::Forms::Label^  fcgLBVppTweakSaturation;
private: System::Windows::Forms::TrackBar^  fcgTBVppTweakGamma;
private: System::Windows::Forms::Label^  fcgLBVppTweakGamma;
private: System::Windows::Forms::TrackBar^  fcgTBVppTweakContrast;
private: System::Windows::Forms::Label^  fcgLBVppTweakContrast;
private: System::Windows::Forms::TrackBar^  fcgTBVppTweakBrightness;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppTweakGamma;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppTweakSaturation;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppTweakHue;
private: System::Windows::Forms::Label^  fcgLBVppTweakBrightness;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppTweakContrast;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppTweakBrightness;






















































































































    private: System::ComponentModel::IContainer^  components;


    

    private:
        /// <summary>
        /// 必要なデザイナ変数です。
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// デザイナ サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディタで変更しないでください。
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmConfig::typeid));
            this->fcgtoolStripSettings = (gcnew System::Windows::Forms::ToolStrip());
            this->fcgTSBSave = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgTSBSaveNew = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgTSBDelete = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgtoolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
            this->fcgTSSettings = (gcnew System::Windows::Forms::ToolStripDropDownButton());
            this->fcgTSBBitrateCalc = (gcnew System::Windows::Forms::ToolStripButton());
            this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
            this->fcgTSBOtherSettings = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgTSLSettingsNotes = (gcnew System::Windows::Forms::ToolStripLabel());
            this->fcgTSTSettingsNotes = (gcnew System::Windows::Forms::ToolStripTextBox());
            this->fcgtabControlMux = (gcnew System::Windows::Forms::TabControl());
            this->fcgtabPageMP4 = (gcnew System::Windows::Forms::TabPage());
            this->fcgBTMP4RawPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMP4RawPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBMP4RawPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBMP4MuxApple = (gcnew System::Windows::Forms::CheckBox());
            this->fcgBTMP4BoxTempDir = (gcnew System::Windows::Forms::Button());
            this->fcgTXMP4BoxTempDir = (gcnew System::Windows::Forms::TextBox());
            this->fcgCXMP4BoxTempDir = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMP4BoxTempDir = (gcnew System::Windows::Forms::Label());
            this->fcgBTTC2MP4Path = (gcnew System::Windows::Forms::Button());
            this->fcgTXTC2MP4Path = (gcnew System::Windows::Forms::TextBox());
            this->fcgBTMP4MuxerPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMP4MuxerPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBTC2MP4Path = (gcnew System::Windows::Forms::Label());
            this->fcgLBMP4MuxerPath = (gcnew System::Windows::Forms::Label());
            this->fcgCXMP4CmdEx = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMP4CmdEx = (gcnew System::Windows::Forms::Label());
            this->fcgCBMP4MuxerExt = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageMKV = (gcnew System::Windows::Forms::TabPage());
            this->fcgBTMKVMuxerPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMKVMuxerPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBMKVMuxerPath = (gcnew System::Windows::Forms::Label());
            this->fcgCXMKVCmdEx = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMKVMuxerCmdEx = (gcnew System::Windows::Forms::Label());
            this->fcgCBMKVMuxerExt = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageMPG = (gcnew System::Windows::Forms::TabPage());
            this->fcgBTMPGMuxerPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMPGMuxerPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBMPGMuxerPath = (gcnew System::Windows::Forms::Label());
            this->fcgCXMPGCmdEx = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMPGMuxerCmdEx = (gcnew System::Windows::Forms::Label());
            this->fcgCBMPGMuxerExt = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageMux = (gcnew System::Windows::Forms::TabPage());
            this->fcgCXMuxPriority = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMuxPriority = (gcnew System::Windows::Forms::Label());
            this->fcgCBMuxMinimize = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageBat = (gcnew System::Windows::Forms::TabPage());
            this->fcgLBBatAfterString = (gcnew System::Windows::Forms::Label());
            this->fcgLBBatBeforeString = (gcnew System::Windows::Forms::Label());
            this->fcgPNSeparator = (gcnew System::Windows::Forms::Panel());
            this->fcgBTBatBeforePath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatBeforePath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatBeforePath = (gcnew System::Windows::Forms::Label());
            this->fcgCBWaitForBatBefore = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBRunBatBefore = (gcnew System::Windows::Forms::CheckBox());
            this->fcgBTBatAfterPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatAfterPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatAfterPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBWaitForBatAfter = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBRunBatAfter = (gcnew System::Windows::Forms::CheckBox());
            this->fcgTXCmd = (gcnew System::Windows::Forms::TextBox());
            this->fcgBTCancel = (gcnew System::Windows::Forms::Button());
            this->fcgBTOK = (gcnew System::Windows::Forms::Button());
            this->fcgBTDefault = (gcnew System::Windows::Forms::Button());
            this->fcgLBVersionDate = (gcnew System::Windows::Forms::Label());
            this->fcgLBVersion = (gcnew System::Windows::Forms::Label());
            this->fcgfolderBrowserTemp = (gcnew System::Windows::Forms::FolderBrowserDialog());
            this->fcgOpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->fcgTTEx = (gcnew System::Windows::Forms::ToolTip(this->components));
            this->fcgtabControlNVEnc = (gcnew System::Windows::Forms::TabControl());
            this->tabPageVideoEnc = (gcnew System::Windows::Forms::TabPage());
            this->fcgPNHEVC = (gcnew System::Windows::Forms::Panel());
            this->fcgLBHEVCOutBitDepth = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCOutBitDepth = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBFullrangeHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgCBFullrangeHEVC = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXVideoFormatHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBVideoFormatHEVC = (gcnew System::Windows::Forms::Label());
            this->fcggroupBoxColorHEVC = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCXTransferHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorPrimHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorMatrixHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBTransferHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorPrimHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorMatrixHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgLBHEVCProfile = (gcnew System::Windows::Forms::Label());
            this->fxgLBHEVCTier = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCTier = (gcnew System::Windows::Forms::ComboBox());
            this->fxgCXHEVCLevel = (gcnew System::Windows::Forms::ComboBox());
            this->fcgPNBitrate = (gcnew System::Windows::Forms::Panel());
            this->fcgLBVBRTragetQuality2 = (gcnew System::Windows::Forms::Label());
            this->fcgNUVBRTragetQuality = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBVBRTragetQuality = (gcnew System::Windows::Forms::Label());
            this->fcgLBBitrate = (gcnew System::Windows::Forms::Label());
            this->fcgNUBitrate = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBBitrate2 = (gcnew System::Windows::Forms::Label());
            this->fcgNUMaxkbps = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBMaxkbps = (gcnew System::Windows::Forms::Label());
            this->fcgLBMaxBitrate2 = (gcnew System::Windows::Forms::Label());
            this->fcgLBWeightP = (gcnew System::Windows::Forms::Label());
            this->fcgLBInterlaced = (gcnew System::Windows::Forms::Label());
            this->fcgCBWeightP = (gcnew System::Windows::Forms::CheckBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->fcgLBLookaheadDisable = (gcnew System::Windows::Forms::Label());
            this->fcgNULookaheadDepth = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBAQStrengthAuto = (gcnew System::Windows::Forms::Label());
            this->fcgCXInterlaced = (gcnew System::Windows::Forms::ComboBox());
            this->fcgNUAQStrength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBAQStrength = (gcnew System::Windows::Forms::Label());
            this->fcgCXAQ = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBLookaheadDepth = (gcnew System::Windows::Forms::Label());
            this->fcgLBAQ = (gcnew System::Windows::Forms::Label());
            this->fcgNUVBVBufsize = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgGroupBoxAspectRatio = (gcnew System::Windows::Forms::GroupBox());
            this->fcgLBAspectRatio = (gcnew System::Windows::Forms::Label());
            this->fcgNUAspectRatioY = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUAspectRatioX = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCXAspectRatio = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBVBVBufsize = (gcnew System::Windows::Forms::Label());
            this->fcgCBAFS = (gcnew System::Windows::Forms::CheckBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->fcgCXEncCodec = (gcnew System::Windows::Forms::ComboBox());
            this->fcgNURefFrames = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBRefFrames = (gcnew System::Windows::Forms::Label());
            this->fcgNUBframes = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBBframes = (gcnew System::Windows::Forms::Label());
            this->fcgLBGOPLengthAuto = (gcnew System::Windows::Forms::Label());
            this->fcgNUGopLength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBGOPLength = (gcnew System::Windows::Forms::Label());
            this->fcgLBEncMode = (gcnew System::Windows::Forms::Label());
            this->fcgCXEncMode = (gcnew System::Windows::Forms::ComboBox());
            this->fcgPBNVEncLogoEnabled = (gcnew System::Windows::Forms::PictureBox());
            this->fcgPBNVEncLogoDisabled = (gcnew System::Windows::Forms::PictureBox());
            this->fcgPNH264 = (gcnew System::Windows::Forms::Panel());
            this->fcgLBBluray = (gcnew System::Windows::Forms::Label());
            this->fcgCBBluray = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBCodecProfile = (gcnew System::Windows::Forms::Label());
            this->fcgLBCodecLevel = (gcnew System::Windows::Forms::Label());
            this->fcgCXCodecProfile = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXCodecLevel = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBFullrangeH264 = (gcnew System::Windows::Forms::Label());
            this->fcgCBFullrangeH264 = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXVideoFormatH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBVideoFormatH264 = (gcnew System::Windows::Forms::Label());
            this->fcggroupBoxColorH264 = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCXTransferH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorPrimH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorMatrixH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBTransferH264 = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorPrimH264 = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorMatrixH264 = (gcnew System::Windows::Forms::Label());
            this->fcgPNQP = (gcnew System::Windows::Forms::Panel());
            this->fcgLBQPI = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPI = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUQPP = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUQPB = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBQPP = (gcnew System::Windows::Forms::Label());
            this->fcgLBQPB = (gcnew System::Windows::Forms::Label());
            this->tabPageVideoDetail = (gcnew System::Windows::Forms::TabPage());
            this->fcgCBAuoTcfileout = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBTempDir = (gcnew System::Windows::Forms::Label());
            this->fcgBTCustomTempDir = (gcnew System::Windows::Forms::Button());
            this->fcgTXCustomTempDir = (gcnew System::Windows::Forms::TextBox());
            this->fcgCXTempDir = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBCudaSchdule = (gcnew System::Windows::Forms::Label());
            this->fcgCXCudaSchdule = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCBPerfMonitor = (gcnew System::Windows::Forms::CheckBox());
            this->fcgGroupBoxQulaityStg = (gcnew System::Windows::Forms::GroupBox());
            this->fcgBTQualityStg = (gcnew System::Windows::Forms::Button());
            this->fcgCXQualityPreset = (gcnew System::Windows::Forms::ComboBox());
            this->groupBoxQPDetail = (gcnew System::Windows::Forms::GroupBox());
            this->fcgLBQPDetailB = (gcnew System::Windows::Forms::Label());
            this->fcgLBQPDetailP = (gcnew System::Windows::Forms::Label());
            this->fcgLBQPDetailI = (gcnew System::Windows::Forms::Label());
            this->fcgCBQPInit = (gcnew System::Windows::Forms::CheckBox());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPInitB = (gcnew System::Windows::Forms::NumericUpDown());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPInitP = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUQPInitI = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBQPMin = (gcnew System::Windows::Forms::CheckBox());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPMinB = (gcnew System::Windows::Forms::NumericUpDown());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPMinP = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUQPMinI = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBQPMax = (gcnew System::Windows::Forms::CheckBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPMaxB = (gcnew System::Windows::Forms::NumericUpDown());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPMaxP = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUQPMaxI = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBDevice = (gcnew System::Windows::Forms::Label());
            this->fcgCXDevice = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBSlices = (gcnew System::Windows::Forms::Label());
            this->fcgNUSlices = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgPNH264Detail = (gcnew System::Windows::Forms::Panel());
            this->fcgLBDeblock = (gcnew System::Windows::Forms::Label());
            this->fcgCXAdaptiveTransform = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAdaptiveTransform = (gcnew System::Windows::Forms::Label());
            this->fcgCXBDirectMode = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBBDirectMode = (gcnew System::Windows::Forms::Label());
            this->fcgLBMVPrecision = (gcnew System::Windows::Forms::Label());
            this->fcgCXMVPrecision = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCBDeblock = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBCABAC = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBCABAC = (gcnew System::Windows::Forms::Label());
            this->fcgPNHEVCDetail = (gcnew System::Windows::Forms::Panel());
            this->fcgLBHEVCMinCUSize = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCMinCUSize = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBHEVCMaxCUSize = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCMaxCUSize = (gcnew System::Windows::Forms::ComboBox());
            this->tabPageExOpt = (gcnew System::Windows::Forms::TabPage());
            this->fcgCBVppTweakEnable = (gcnew System::Windows::Forms::CheckBox());
            this->fcggroupBoxVppTweak = (gcnew System::Windows::Forms::GroupBox());
            this->fcgTBVppTweakHue = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppTweakHue = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppTweakSaturation = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppTweakSaturation = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppTweakGamma = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppTweakGamma = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppTweakContrast = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppTweakContrast = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppTweakBrightness = (gcnew System::Windows::Forms::TrackBar());
            this->fcgNUVppTweakGamma = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppTweakSaturation = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppTweakHue = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBVppTweakBrightness = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppTweakContrast = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppTweakBrightness = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBVppPerfMonitor = (gcnew System::Windows::Forms::CheckBox());
            this->fcggroupBoxVppDetailEnahance = (gcnew System::Windows::Forms::GroupBox());
            this->fcgPNVppEdgelevel = (gcnew System::Windows::Forms::Panel());
            this->fcgLBVppEdgelevelWhite = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppEdgelevelWhite = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBVppEdgelevelThreshold = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppEdgelevelBlack = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppEdgelevelStrength = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppEdgelevelThreshold = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppEdgelevelBlack = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppEdgelevelStrength = (gcnew System::Windows::Forms::NumericUpDown());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCXVppDetailEnhance = (gcnew System::Windows::Forms::ComboBox());
            this->fcgPNVppUnsharp = (gcnew System::Windows::Forms::Panel());
            this->fcgLBVppUnsharpThreshold = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppUnsharpWeight = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppUnsharpRadius = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppUnsharpThreshold = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppUnsharpWeight = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppUnsharpRadius = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBVppAfsEnable = (gcnew System::Windows::Forms::CheckBox());
            this->fcggroupBoxVppAfs = (gcnew System::Windows::Forms::GroupBox());
            this->fcgTBVppAfsThreCMotion = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppAfsThreCMotion = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppAfsThreYMotion = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppAfsThreYmotion = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppAfsThreDeint = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppAfsThreDeint = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppAfsThreShift = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppAfsThreShift = (gcnew System::Windows::Forms::Label());
            this->fcgTBVppAfsCoeffShift = (gcnew System::Windows::Forms::TrackBar());
            this->fcgLBVppAfsCoeffShift = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppAfsUp = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppAfsRight = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppAfsLeft = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppAfsBottom = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppAfsUp = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgTBVppAfsMethodSwitch = (gcnew System::Windows::Forms::TrackBar());
            this->fcgCBVppAfs24fps = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBVppAfsTune = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBVppAfsSmooth = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBVppAfsDrop = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBVppAfsShift = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBVppAfsAnalyze = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppAfsThreCMotion = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppAfsThreShift = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppAfsThreDeint = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppAfsThreYMotion = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBVppAfsMethodSwitch = (gcnew System::Windows::Forms::Label());
            this->fcgCXVppAfsAnalyze = (gcnew System::Windows::Forms::ComboBox());
            this->fcgNUVppAfsCoeffShift = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppAfsMethodSwitch = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBVppDebandEnable = (gcnew System::Windows::Forms::CheckBox());
            this->fcggroupBoxVppDeband = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCBVppDebandRandEachFrame = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBVppDebandBlurFirst = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBVppDebandSample = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDebandDitherC = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDebandDitherY = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDebandDither = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDebandThreCr = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDebandThreCb = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDebandThreY = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppDebandDitherC = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDebandDitherY = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDebandThreCr = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDebandThreCb = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBVppDebandThreshold = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDebandRange = (gcnew System::Windows::Forms::Label());
            this->fcgCXVppDebandSample = (gcnew System::Windows::Forms::ComboBox());
            this->fcgNUVppDebandThreY = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDebandRange = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcggroupBoxVppDenoise = (gcnew System::Windows::Forms::GroupBox());
            this->fcgPNVppDenoiseKnn = (gcnew System::Windows::Forms::Panel());
            this->fcgLBVppDenoiseKnnThreshold = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoiseKnnStrength = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoiseKnnRadius = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppDenoiseKnnThreshold = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoiseKnnStrength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoiseKnnRadius = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgPNVppDenoisePmd = (gcnew System::Windows::Forms::Panel());
            this->fcgLBVppDenoisePmdThreshold = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoisePmdStrength = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoisePmdApplyCount = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppDenoisePmdThreshold = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoisePmdStrength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoisePmdApplyCount = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCXVppDenoiseMethod = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCBVppResize = (gcnew System::Windows::Forms::CheckBox());
            this->fcggroupBoxResize = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCXVppResizeAlg = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBVppResize = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppResizeHeight = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppResizeWidth = (gcnew System::Windows::Forms::NumericUpDown());
            this->tabPageNVEncFeatures = (gcnew System::Windows::Forms::TabPage());
            this->fcgTabControlFeatures = (gcnew System::Windows::Forms::TabControl());
            this->fcgTabPageH264 = (gcnew System::Windows::Forms::TabPage());
            this->fcgDGVFeaturesH264 = (gcnew System::Windows::Forms::DataGridView());
            this->fcgTabPageHEVC = (gcnew System::Windows::Forms::TabPage());
            this->fcgDGVFeaturesHEVC = (gcnew System::Windows::Forms::DataGridView());
            this->fcgLBOSInfo = (gcnew System::Windows::Forms::Label());
            this->fcgLBOSInfoLabel = (gcnew System::Windows::Forms::Label());
            this->fcgLBCPUInfoOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->fcgLBCPUInfoLabelOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->fcgLBGPUInfoOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->fcgLBGPUInfoLabelOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->fcgCSExeFiles = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->fcgTSExeFileshelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->fcgLBguiExBlog = (gcnew System::Windows::Forms::LinkLabel());
            this->fcgtabControlAudio = (gcnew System::Windows::Forms::TabControl());
            this->fcgtabPageAudioMain = (gcnew System::Windows::Forms::TabPage());
            this->fcgCXAudioDelayCut = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioDelayCut = (gcnew System::Windows::Forms::Label());
            this->fcgCBAudioEncTiming = (gcnew System::Windows::Forms::Label());
            this->fcgCXAudioEncTiming = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXAudioTempDir = (gcnew System::Windows::Forms::ComboBox());
            this->fcgTXCustomAudioTempDir = (gcnew System::Windows::Forms::TextBox());
            this->fcgBTCustomAudioTempDir = (gcnew System::Windows::Forms::Button());
            this->fcgCBAudioUsePipe = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBAudioBitrate = (gcnew System::Windows::Forms::Label());
            this->fcgNUAudioBitrate = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBAudio2pass = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXAudioEncMode = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioEncMode = (gcnew System::Windows::Forms::Label());
            this->fcgBTAudioEncoderPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXAudioEncoderPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBAudioEncoderPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBAudioOnly = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBFAWCheck = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXAudioEncoder = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioEncoder = (gcnew System::Windows::Forms::Label());
            this->fcgLBAudioTemp = (gcnew System::Windows::Forms::Label());
            this->fcgtabPageAudioOther = (gcnew System::Windows::Forms::TabPage());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->fcgLBBatAfterAudioString = (gcnew System::Windows::Forms::Label());
            this->fcgLBBatBeforeAudioString = (gcnew System::Windows::Forms::Label());
            this->fcgBTBatAfterAudioPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatAfterAudioPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatAfterAudioPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBRunBatAfterAudio = (gcnew System::Windows::Forms::CheckBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->fcgBTBatBeforeAudioPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatBeforeAudioPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatBeforeAudioPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBRunBatBeforeAudio = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXAudioPriority = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioPriority = (gcnew System::Windows::Forms::Label());
            this->fcgtoolStripSettings->SuspendLayout();
            this->fcgtabControlMux->SuspendLayout();
            this->fcgtabPageMP4->SuspendLayout();
            this->fcgtabPageMKV->SuspendLayout();
            this->fcgtabPageMPG->SuspendLayout();
            this->fcgtabPageMux->SuspendLayout();
            this->fcgtabPageBat->SuspendLayout();
            this->fcgtabControlNVEnc->SuspendLayout();
            this->tabPageVideoEnc->SuspendLayout();
            this->fcgPNHEVC->SuspendLayout();
            this->fcggroupBoxColorHEVC->SuspendLayout();
            this->fcgPNBitrate->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVBRTragetQuality))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBitrate))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUMaxkbps))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNULookaheadDepth))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAQStrength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVBVBufsize))->BeginInit();
            this->fcgGroupBoxAspectRatio->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioY))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioX))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNURefFrames))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBframes))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUGopLength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoEnabled))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoDisabled))->BeginInit();
            this->fcgPNH264->SuspendLayout();
            this->fcggroupBoxColorH264->SuspendLayout();
            this->fcgPNQP->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPI))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPP))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPB))->BeginInit();
            this->tabPageVideoDetail->SuspendLayout();
            this->fcgGroupBoxQulaityStg->SuspendLayout();
            this->groupBoxQPDetail->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPInitB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPInitP))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPInitI))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMinB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMinP))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMinI))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMaxB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMaxP))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMaxI))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUSlices))->BeginInit();
            this->fcgPNH264Detail->SuspendLayout();
            this->fcgPNHEVCDetail->SuspendLayout();
            this->tabPageExOpt->SuspendLayout();
            this->fcggroupBoxVppTweak->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakHue))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakSaturation))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakGamma))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakContrast))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakBrightness))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakGamma))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakSaturation))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakHue))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakContrast))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakBrightness))->BeginInit();
            this->fcggroupBoxVppDetailEnahance->SuspendLayout();
            this->fcgPNVppEdgelevel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelWhite))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelThreshold))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelBlack))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelStrength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
            this->fcgPNVppUnsharp->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppUnsharpThreshold))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppUnsharpWeight))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppUnsharpRadius))->BeginInit();
            this->fcggroupBoxVppAfs->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreCMotion))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreYMotion))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreDeint))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreShift))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsCoeffShift))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsRight))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsLeft))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsBottom))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsUp))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsMethodSwitch))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreCMotion))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreShift))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreDeint))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreYMotion))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsCoeffShift))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsMethodSwitch))->BeginInit();
            this->fcggroupBoxVppDeband->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandDitherC))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandDitherY))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandThreCr))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandThreCb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandThreY))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandRange))->BeginInit();
            this->fcggroupBoxVppDenoise->SuspendLayout();
            this->fcgPNVppDenoiseKnn->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnThreshold))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnStrength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnRadius))->BeginInit();
            this->fcgPNVppDenoisePmd->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdThreshold))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdStrength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdApplyCount))->BeginInit();
            this->fcggroupBoxResize->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeHeight))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeWidth))->BeginInit();
            this->tabPageNVEncFeatures->SuspendLayout();
            this->fcgTabControlFeatures->SuspendLayout();
            this->fcgTabPageH264->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesH264))->BeginInit();
            this->fcgTabPageHEVC->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesHEVC))->BeginInit();
            this->fcgCSExeFiles->SuspendLayout();
            this->fcgtabControlAudio->SuspendLayout();
            this->fcgtabPageAudioMain->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAudioBitrate))->BeginInit();
            this->fcgtabPageAudioOther->SuspendLayout();
            this->SuspendLayout();
            // 
            // fcgtoolStripSettings
            // 
            this->fcgtoolStripSettings->ImageScalingSize = System::Drawing::Size(18, 18);
            this->fcgtoolStripSettings->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
                this->fcgTSBSave,
                    this->fcgTSBSaveNew, this->fcgTSBDelete, this->fcgtoolStripSeparator1, this->fcgTSSettings, this->fcgTSBBitrateCalc, this->toolStripSeparator2,
                    this->fcgTSBOtherSettings, this->fcgTSLSettingsNotes, this->fcgTSTSettingsNotes
            });
            this->fcgtoolStripSettings->Location = System::Drawing::Point(0, 0);
            this->fcgtoolStripSettings->Name = L"fcgtoolStripSettings";
            this->fcgtoolStripSettings->Size = System::Drawing::Size(1260, 27);
            this->fcgtoolStripSettings->TabIndex = 1;
            this->fcgtoolStripSettings->Text = L"toolStrip1";
            // 
            // fcgTSBSave
            // 
            this->fcgTSBSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBSave.Image")));
            this->fcgTSBSave->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBSave->Name = L"fcgTSBSave";
            this->fcgTSBSave->Size = System::Drawing::Size(102, 24);
            this->fcgTSBSave->Text = L"上書き保存";
            this->fcgTSBSave->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBSave_Click);
            // 
            // fcgTSBSaveNew
            // 
            this->fcgTSBSaveNew->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBSaveNew.Image")));
            this->fcgTSBSaveNew->ImageTransparentColor = System::Drawing::Color::Black;
            this->fcgTSBSaveNew->Name = L"fcgTSBSaveNew";
            this->fcgTSBSaveNew->Size = System::Drawing::Size(91, 24);
            this->fcgTSBSaveNew->Text = L"新規保存";
            this->fcgTSBSaveNew->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBSaveNew_Click);
            // 
            // fcgTSBDelete
            // 
            this->fcgTSBDelete->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBDelete.Image")));
            this->fcgTSBDelete->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBDelete->Name = L"fcgTSBDelete";
            this->fcgTSBDelete->Size = System::Drawing::Size(61, 24);
            this->fcgTSBDelete->Text = L"削除";
            this->fcgTSBDelete->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBDelete_Click);
            // 
            // fcgtoolStripSeparator1
            // 
            this->fcgtoolStripSeparator1->Name = L"fcgtoolStripSeparator1";
            this->fcgtoolStripSeparator1->Size = System::Drawing::Size(6, 27);
            // 
            // fcgTSSettings
            // 
            this->fcgTSSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSSettings.Image")));
            this->fcgTSSettings->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSSettings->Name = L"fcgTSSettings";
            this->fcgTSSettings->Size = System::Drawing::Size(95, 24);
            this->fcgTSSettings->Text = L"プリセット";
            this->fcgTSSettings->DropDownItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &frmConfig::fcgTSSettings_DropDownItemClicked);
            this->fcgTSSettings->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSSettings_Click);
            // 
            // fcgTSBBitrateCalc
            // 
            this->fcgTSBBitrateCalc->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
            this->fcgTSBBitrateCalc->CheckOnClick = true;
            this->fcgTSBBitrateCalc->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
            this->fcgTSBBitrateCalc->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBBitrateCalc.Image")));
            this->fcgTSBBitrateCalc->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBBitrateCalc->Name = L"fcgTSBBitrateCalc";
            this->fcgTSBBitrateCalc->Size = System::Drawing::Size(120, 24);
            this->fcgTSBBitrateCalc->Text = L"ビットレート計算機";
            this->fcgTSBBitrateCalc->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgTSBBitrateCalc_CheckedChanged);
            // 
            // toolStripSeparator2
            // 
            this->toolStripSeparator2->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
            this->toolStripSeparator2->Name = L"toolStripSeparator2";
            this->toolStripSeparator2->Size = System::Drawing::Size(6, 27);
            // 
            // fcgTSBOtherSettings
            // 
            this->fcgTSBOtherSettings->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
            this->fcgTSBOtherSettings->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
            this->fcgTSBOtherSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBOtherSettings.Image")));
            this->fcgTSBOtherSettings->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBOtherSettings->Name = L"fcgTSBOtherSettings";
            this->fcgTSBOtherSettings->Size = System::Drawing::Size(93, 24);
            this->fcgTSBOtherSettings->Text = L"その他の設定";
            this->fcgTSBOtherSettings->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBOtherSettings_Click);
            // 
            // fcgTSLSettingsNotes
            // 
            this->fcgTSLSettingsNotes->DoubleClickEnabled = true;
            this->fcgTSLSettingsNotes->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgTSLSettingsNotes->Margin = System::Windows::Forms::Padding(3, 1, 0, 2);
            this->fcgTSLSettingsNotes->Name = L"fcgTSLSettingsNotes";
            this->fcgTSLSettingsNotes->Overflow = System::Windows::Forms::ToolStripItemOverflow::Never;
            this->fcgTSLSettingsNotes->Size = System::Drawing::Size(57, 24);
            this->fcgTSLSettingsNotes->Text = L"メモ表示";
            this->fcgTSLSettingsNotes->DoubleClick += gcnew System::EventHandler(this, &frmConfig::fcgTSLSettingsNotes_DoubleClick);
            // 
            // fcgTSTSettingsNotes
            // 
            this->fcgTSTSettingsNotes->BackColor = System::Drawing::SystemColors::Window;
            this->fcgTSTSettingsNotes->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgTSTSettingsNotes->Margin = System::Windows::Forms::Padding(3, 0, 1, 0);
            this->fcgTSTSettingsNotes->Name = L"fcgTSTSettingsNotes";
            this->fcgTSTSettingsNotes->Size = System::Drawing::Size(249, 27);
            this->fcgTSTSettingsNotes->Text = L"メモ...";
            this->fcgTSTSettingsNotes->Visible = false;
            this->fcgTSTSettingsNotes->Leave += gcnew System::EventHandler(this, &frmConfig::fcgTSTSettingsNotes_Leave);
            this->fcgTSTSettingsNotes->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmConfig::fcgTSTSettingsNotes_KeyDown);
            this->fcgTSTSettingsNotes->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTSTSettingsNotes_TextChanged);
            // 
            // fcgtabControlMux
            // 
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMP4);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMKV);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMPG);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMux);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageBat);
            this->fcgtabControlMux->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgtabControlMux->Location = System::Drawing::Point(778, 424);
            this->fcgtabControlMux->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabControlMux->Name = L"fcgtabControlMux";
            this->fcgtabControlMux->SelectedIndex = 0;
            this->fcgtabControlMux->Size = System::Drawing::Size(480, 251);
            this->fcgtabControlMux->TabIndex = 3;
            // 
            // fcgtabPageMP4
            // 
            this->fcgtabPageMP4->Controls->Add(this->fcgBTMP4RawPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXMP4RawPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4RawPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgCBMP4MuxApple);
            this->fcgtabPageMP4->Controls->Add(this->fcgBTMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgCXMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgBTTC2MP4Path);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXTC2MP4Path);
            this->fcgtabPageMP4->Controls->Add(this->fcgBTMP4MuxerPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXMP4MuxerPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBTC2MP4Path);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4MuxerPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgCXMP4CmdEx);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4CmdEx);
            this->fcgtabPageMP4->Controls->Add(this->fcgCBMP4MuxerExt);
            this->fcgtabPageMP4->Location = System::Drawing::Point(4, 27);
            this->fcgtabPageMP4->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabPageMP4->Name = L"fcgtabPageMP4";
            this->fcgtabPageMP4->Padding = System::Windows::Forms::Padding(4);
            this->fcgtabPageMP4->Size = System::Drawing::Size(472, 220);
            this->fcgtabPageMP4->TabIndex = 0;
            this->fcgtabPageMP4->Text = L"mp4";
            this->fcgtabPageMP4->UseVisualStyleBackColor = true;
            // 
            // fcgBTMP4RawPath
            // 
            this->fcgBTMP4RawPath->Location = System::Drawing::Point(425, 128);
            this->fcgBTMP4RawPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTMP4RawPath->Name = L"fcgBTMP4RawPath";
            this->fcgBTMP4RawPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTMP4RawPath->TabIndex = 23;
            this->fcgBTMP4RawPath->Text = L"...";
            this->fcgBTMP4RawPath->UseVisualStyleBackColor = true;
            this->fcgBTMP4RawPath->Visible = false;
            this->fcgBTMP4RawPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMP4RawMuxerPath_Click);
            // 
            // fcgTXMP4RawPath
            // 
            this->fcgTXMP4RawPath->AllowDrop = true;
            this->fcgTXMP4RawPath->Location = System::Drawing::Point(170, 129);
            this->fcgTXMP4RawPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXMP4RawPath->Name = L"fcgTXMP4RawPath";
            this->fcgTXMP4RawPath->Size = System::Drawing::Size(252, 25);
            this->fcgTXMP4RawPath->TabIndex = 22;
            this->fcgTXMP4RawPath->Visible = false;
            this->fcgTXMP4RawPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMP4RawMuxerPath_TextChanged);
            this->fcgTXMP4RawPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMP4RawPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBMP4RawPath
            // 
            this->fcgLBMP4RawPath->AutoSize = true;
            this->fcgLBMP4RawPath->Location = System::Drawing::Point(5, 132);
            this->fcgLBMP4RawPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMP4RawPath->Name = L"fcgLBMP4RawPath";
            this->fcgLBMP4RawPath->Size = System::Drawing::Size(61, 18);
            this->fcgLBMP4RawPath->TabIndex = 21;
            this->fcgLBMP4RawPath->Text = L"～の指定";
            this->fcgLBMP4RawPath->Visible = false;
            // 
            // fcgCBMP4MuxApple
            // 
            this->fcgCBMP4MuxApple->AutoSize = true;
            this->fcgCBMP4MuxApple->Location = System::Drawing::Point(318, 42);
            this->fcgCBMP4MuxApple->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBMP4MuxApple->Name = L"fcgCBMP4MuxApple";
            this->fcgCBMP4MuxApple->Size = System::Drawing::Size(136, 22);
            this->fcgCBMP4MuxApple->TabIndex = 20;
            this->fcgCBMP4MuxApple->Tag = L"chValue";
            this->fcgCBMP4MuxApple->Text = L"Apple形式に対応";
            this->fcgCBMP4MuxApple->UseVisualStyleBackColor = true;
            // 
            // fcgBTMP4BoxTempDir
            // 
            this->fcgBTMP4BoxTempDir->Location = System::Drawing::Point(425, 182);
            this->fcgBTMP4BoxTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTMP4BoxTempDir->Name = L"fcgBTMP4BoxTempDir";
            this->fcgBTMP4BoxTempDir->Size = System::Drawing::Size(38, 29);
            this->fcgBTMP4BoxTempDir->TabIndex = 8;
            this->fcgBTMP4BoxTempDir->Text = L"...";
            this->fcgBTMP4BoxTempDir->UseVisualStyleBackColor = true;
            this->fcgBTMP4BoxTempDir->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMP4BoxTempDir_Click);
            // 
            // fcgTXMP4BoxTempDir
            // 
            this->fcgTXMP4BoxTempDir->Location = System::Drawing::Point(134, 184);
            this->fcgTXMP4BoxTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXMP4BoxTempDir->Name = L"fcgTXMP4BoxTempDir";
            this->fcgTXMP4BoxTempDir->Size = System::Drawing::Size(283, 25);
            this->fcgTXMP4BoxTempDir->TabIndex = 7;
            this->fcgTXMP4BoxTempDir->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMP4BoxTempDir_TextChanged);
            // 
            // fcgCXMP4BoxTempDir
            // 
            this->fcgCXMP4BoxTempDir->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMP4BoxTempDir->FormattingEnabled = true;
            this->fcgCXMP4BoxTempDir->Location = System::Drawing::Point(181, 149);
            this->fcgCXMP4BoxTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXMP4BoxTempDir->Name = L"fcgCXMP4BoxTempDir";
            this->fcgCXMP4BoxTempDir->Size = System::Drawing::Size(256, 26);
            this->fcgCXMP4BoxTempDir->TabIndex = 6;
            this->fcgCXMP4BoxTempDir->Tag = L"chValue";
            // 
            // fcgLBMP4BoxTempDir
            // 
            this->fcgLBMP4BoxTempDir->AutoSize = true;
            this->fcgLBMP4BoxTempDir->Location = System::Drawing::Point(31, 152);
            this->fcgLBMP4BoxTempDir->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMP4BoxTempDir->Name = L"fcgLBMP4BoxTempDir";
            this->fcgLBMP4BoxTempDir->Size = System::Drawing::Size(131, 18);
            this->fcgLBMP4BoxTempDir->TabIndex = 18;
            this->fcgLBMP4BoxTempDir->Text = L"mp4box一時フォルダ";
            // 
            // fcgBTTC2MP4Path
            // 
            this->fcgBTTC2MP4Path->Location = System::Drawing::Point(425, 100);
            this->fcgBTTC2MP4Path->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTTC2MP4Path->Name = L"fcgBTTC2MP4Path";
            this->fcgBTTC2MP4Path->Size = System::Drawing::Size(38, 29);
            this->fcgBTTC2MP4Path->TabIndex = 5;
            this->fcgBTTC2MP4Path->Text = L"...";
            this->fcgBTTC2MP4Path->UseVisualStyleBackColor = true;
            this->fcgBTTC2MP4Path->Visible = false;
            this->fcgBTTC2MP4Path->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTTC2MP4Path_Click);
            // 
            // fcgTXTC2MP4Path
            // 
            this->fcgTXTC2MP4Path->AllowDrop = true;
            this->fcgTXTC2MP4Path->Location = System::Drawing::Point(170, 101);
            this->fcgTXTC2MP4Path->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXTC2MP4Path->Name = L"fcgTXTC2MP4Path";
            this->fcgTXTC2MP4Path->Size = System::Drawing::Size(252, 25);
            this->fcgTXTC2MP4Path->TabIndex = 4;
            this->fcgTXTC2MP4Path->Visible = false;
            this->fcgTXTC2MP4Path->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXTC2MP4Path_TextChanged);
            this->fcgTXTC2MP4Path->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXTC2MP4Path->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgBTMP4MuxerPath
            // 
            this->fcgBTMP4MuxerPath->Location = System::Drawing::Point(425, 72);
            this->fcgBTMP4MuxerPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTMP4MuxerPath->Name = L"fcgBTMP4MuxerPath";
            this->fcgBTMP4MuxerPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTMP4MuxerPath->TabIndex = 3;
            this->fcgBTMP4MuxerPath->Text = L"...";
            this->fcgBTMP4MuxerPath->UseVisualStyleBackColor = true;
            this->fcgBTMP4MuxerPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMP4MuxerPath_Click);
            // 
            // fcgTXMP4MuxerPath
            // 
            this->fcgTXMP4MuxerPath->AllowDrop = true;
            this->fcgTXMP4MuxerPath->Location = System::Drawing::Point(170, 74);
            this->fcgTXMP4MuxerPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXMP4MuxerPath->Name = L"fcgTXMP4MuxerPath";
            this->fcgTXMP4MuxerPath->Size = System::Drawing::Size(252, 25);
            this->fcgTXMP4MuxerPath->TabIndex = 2;
            this->fcgTXMP4MuxerPath->Tag = L"";
            this->fcgTXMP4MuxerPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMP4MuxerPath_TextChanged);
            this->fcgTXMP4MuxerPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMP4MuxerPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBTC2MP4Path
            // 
            this->fcgLBTC2MP4Path->AutoSize = true;
            this->fcgLBTC2MP4Path->Location = System::Drawing::Point(5, 105);
            this->fcgLBTC2MP4Path->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBTC2MP4Path->Name = L"fcgLBTC2MP4Path";
            this->fcgLBTC2MP4Path->Size = System::Drawing::Size(61, 18);
            this->fcgLBTC2MP4Path->TabIndex = 4;
            this->fcgLBTC2MP4Path->Text = L"～の指定";
            this->fcgLBTC2MP4Path->Visible = false;
            // 
            // fcgLBMP4MuxerPath
            // 
            this->fcgLBMP4MuxerPath->AutoSize = true;
            this->fcgLBMP4MuxerPath->Location = System::Drawing::Point(5, 78);
            this->fcgLBMP4MuxerPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMP4MuxerPath->Name = L"fcgLBMP4MuxerPath";
            this->fcgLBMP4MuxerPath->Size = System::Drawing::Size(61, 18);
            this->fcgLBMP4MuxerPath->TabIndex = 3;
            this->fcgLBMP4MuxerPath->Text = L"～の指定";
            // 
            // fcgCXMP4CmdEx
            // 
            this->fcgCXMP4CmdEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMP4CmdEx->FormattingEnabled = true;
            this->fcgCXMP4CmdEx->Location = System::Drawing::Point(266, 9);
            this->fcgCXMP4CmdEx->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXMP4CmdEx->Name = L"fcgCXMP4CmdEx";
            this->fcgCXMP4CmdEx->Size = System::Drawing::Size(195, 26);
            this->fcgCXMP4CmdEx->TabIndex = 1;
            this->fcgCXMP4CmdEx->Tag = L"chValue";
            // 
            // fcgLBMP4CmdEx
            // 
            this->fcgLBMP4CmdEx->AutoSize = true;
            this->fcgLBMP4CmdEx->Location = System::Drawing::Point(174, 12);
            this->fcgLBMP4CmdEx->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMP4CmdEx->Name = L"fcgLBMP4CmdEx";
            this->fcgLBMP4CmdEx->Size = System::Drawing::Size(86, 18);
            this->fcgLBMP4CmdEx->TabIndex = 1;
            this->fcgLBMP4CmdEx->Text = L"拡張オプション";
            // 
            // fcgCBMP4MuxerExt
            // 
            this->fcgCBMP4MuxerExt->AutoSize = true;
            this->fcgCBMP4MuxerExt->Location = System::Drawing::Point(12, 11);
            this->fcgCBMP4MuxerExt->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBMP4MuxerExt->Name = L"fcgCBMP4MuxerExt";
            this->fcgCBMP4MuxerExt->Size = System::Drawing::Size(141, 22);
            this->fcgCBMP4MuxerExt->TabIndex = 0;
            this->fcgCBMP4MuxerExt->Tag = L"chValue";
            this->fcgCBMP4MuxerExt->Text = L"外部muxerを使用";
            this->fcgCBMP4MuxerExt->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageMKV
            // 
            this->fcgtabPageMKV->Controls->Add(this->fcgBTMKVMuxerPath);
            this->fcgtabPageMKV->Controls->Add(this->fcgTXMKVMuxerPath);
            this->fcgtabPageMKV->Controls->Add(this->fcgLBMKVMuxerPath);
            this->fcgtabPageMKV->Controls->Add(this->fcgCXMKVCmdEx);
            this->fcgtabPageMKV->Controls->Add(this->fcgLBMKVMuxerCmdEx);
            this->fcgtabPageMKV->Controls->Add(this->fcgCBMKVMuxerExt);
            this->fcgtabPageMKV->Location = System::Drawing::Point(4, 27);
            this->fcgtabPageMKV->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabPageMKV->Name = L"fcgtabPageMKV";
            this->fcgtabPageMKV->Padding = System::Windows::Forms::Padding(4);
            this->fcgtabPageMKV->Size = System::Drawing::Size(472, 220);
            this->fcgtabPageMKV->TabIndex = 1;
            this->fcgtabPageMKV->Text = L"mkv";
            this->fcgtabPageMKV->UseVisualStyleBackColor = true;
            // 
            // fcgBTMKVMuxerPath
            // 
            this->fcgBTMKVMuxerPath->Location = System::Drawing::Point(425, 95);
            this->fcgBTMKVMuxerPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTMKVMuxerPath->Name = L"fcgBTMKVMuxerPath";
            this->fcgBTMKVMuxerPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTMKVMuxerPath->TabIndex = 3;
            this->fcgBTMKVMuxerPath->Text = L"...";
            this->fcgBTMKVMuxerPath->UseVisualStyleBackColor = true;
            this->fcgBTMKVMuxerPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMKVMuxerPath_Click);
            // 
            // fcgTXMKVMuxerPath
            // 
            this->fcgTXMKVMuxerPath->Location = System::Drawing::Point(164, 96);
            this->fcgTXMKVMuxerPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXMKVMuxerPath->Name = L"fcgTXMKVMuxerPath";
            this->fcgTXMKVMuxerPath->Size = System::Drawing::Size(258, 25);
            this->fcgTXMKVMuxerPath->TabIndex = 2;
            this->fcgTXMKVMuxerPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMKVMuxerPath_TextChanged);
            this->fcgTXMKVMuxerPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMKVMuxerPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBMKVMuxerPath
            // 
            this->fcgLBMKVMuxerPath->AutoSize = true;
            this->fcgLBMKVMuxerPath->Location = System::Drawing::Point(5, 100);
            this->fcgLBMKVMuxerPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMKVMuxerPath->Name = L"fcgLBMKVMuxerPath";
            this->fcgLBMKVMuxerPath->Size = System::Drawing::Size(61, 18);
            this->fcgLBMKVMuxerPath->TabIndex = 19;
            this->fcgLBMKVMuxerPath->Text = L"～の指定";
            // 
            // fcgCXMKVCmdEx
            // 
            this->fcgCXMKVCmdEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMKVCmdEx->FormattingEnabled = true;
            this->fcgCXMKVCmdEx->Location = System::Drawing::Point(266, 54);
            this->fcgCXMKVCmdEx->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXMKVCmdEx->Name = L"fcgCXMKVCmdEx";
            this->fcgCXMKVCmdEx->Size = System::Drawing::Size(195, 26);
            this->fcgCXMKVCmdEx->TabIndex = 1;
            this->fcgCXMKVCmdEx->Tag = L"chValue";
            // 
            // fcgLBMKVMuxerCmdEx
            // 
            this->fcgLBMKVMuxerCmdEx->AutoSize = true;
            this->fcgLBMKVMuxerCmdEx->Location = System::Drawing::Point(174, 58);
            this->fcgLBMKVMuxerCmdEx->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMKVMuxerCmdEx->Name = L"fcgLBMKVMuxerCmdEx";
            this->fcgLBMKVMuxerCmdEx->Size = System::Drawing::Size(86, 18);
            this->fcgLBMKVMuxerCmdEx->TabIndex = 17;
            this->fcgLBMKVMuxerCmdEx->Text = L"拡張オプション";
            // 
            // fcgCBMKVMuxerExt
            // 
            this->fcgCBMKVMuxerExt->AutoSize = true;
            this->fcgCBMKVMuxerExt->Location = System::Drawing::Point(12, 56);
            this->fcgCBMKVMuxerExt->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBMKVMuxerExt->Name = L"fcgCBMKVMuxerExt";
            this->fcgCBMKVMuxerExt->Size = System::Drawing::Size(141, 22);
            this->fcgCBMKVMuxerExt->TabIndex = 0;
            this->fcgCBMKVMuxerExt->Tag = L"chValue";
            this->fcgCBMKVMuxerExt->Text = L"外部muxerを使用";
            this->fcgCBMKVMuxerExt->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageMPG
            // 
            this->fcgtabPageMPG->Controls->Add(this->fcgBTMPGMuxerPath);
            this->fcgtabPageMPG->Controls->Add(this->fcgTXMPGMuxerPath);
            this->fcgtabPageMPG->Controls->Add(this->fcgLBMPGMuxerPath);
            this->fcgtabPageMPG->Controls->Add(this->fcgCXMPGCmdEx);
            this->fcgtabPageMPG->Controls->Add(this->fcgLBMPGMuxerCmdEx);
            this->fcgtabPageMPG->Controls->Add(this->fcgCBMPGMuxerExt);
            this->fcgtabPageMPG->Location = System::Drawing::Point(4, 27);
            this->fcgtabPageMPG->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabPageMPG->Name = L"fcgtabPageMPG";
            this->fcgtabPageMPG->Size = System::Drawing::Size(472, 220);
            this->fcgtabPageMPG->TabIndex = 4;
            this->fcgtabPageMPG->Text = L"mpg";
            this->fcgtabPageMPG->UseVisualStyleBackColor = true;
            // 
            // fcgBTMPGMuxerPath
            // 
            this->fcgBTMPGMuxerPath->Location = System::Drawing::Point(426, 115);
            this->fcgBTMPGMuxerPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTMPGMuxerPath->Name = L"fcgBTMPGMuxerPath";
            this->fcgBTMPGMuxerPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTMPGMuxerPath->TabIndex = 23;
            this->fcgBTMPGMuxerPath->Text = L"...";
            this->fcgBTMPGMuxerPath->UseVisualStyleBackColor = true;
            this->fcgBTMPGMuxerPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMPGMuxerPath_Click);
            // 
            // fcgTXMPGMuxerPath
            // 
            this->fcgTXMPGMuxerPath->Location = System::Drawing::Point(165, 116);
            this->fcgTXMPGMuxerPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXMPGMuxerPath->Name = L"fcgTXMPGMuxerPath";
            this->fcgTXMPGMuxerPath->Size = System::Drawing::Size(258, 25);
            this->fcgTXMPGMuxerPath->TabIndex = 22;
            this->fcgTXMPGMuxerPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMPGMuxerPath_TextChanged);
            this->fcgTXMPGMuxerPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMPGMuxerPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBMPGMuxerPath
            // 
            this->fcgLBMPGMuxerPath->AutoSize = true;
            this->fcgLBMPGMuxerPath->Location = System::Drawing::Point(6, 120);
            this->fcgLBMPGMuxerPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMPGMuxerPath->Name = L"fcgLBMPGMuxerPath";
            this->fcgLBMPGMuxerPath->Size = System::Drawing::Size(61, 18);
            this->fcgLBMPGMuxerPath->TabIndex = 25;
            this->fcgLBMPGMuxerPath->Text = L"～の指定";
            // 
            // fcgCXMPGCmdEx
            // 
            this->fcgCXMPGCmdEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMPGCmdEx->FormattingEnabled = true;
            this->fcgCXMPGCmdEx->Location = System::Drawing::Point(268, 74);
            this->fcgCXMPGCmdEx->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXMPGCmdEx->Name = L"fcgCXMPGCmdEx";
            this->fcgCXMPGCmdEx->Size = System::Drawing::Size(195, 26);
            this->fcgCXMPGCmdEx->TabIndex = 21;
            this->fcgCXMPGCmdEx->Tag = L"chValue";
            // 
            // fcgLBMPGMuxerCmdEx
            // 
            this->fcgLBMPGMuxerCmdEx->AutoSize = true;
            this->fcgLBMPGMuxerCmdEx->Location = System::Drawing::Point(175, 78);
            this->fcgLBMPGMuxerCmdEx->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMPGMuxerCmdEx->Name = L"fcgLBMPGMuxerCmdEx";
            this->fcgLBMPGMuxerCmdEx->Size = System::Drawing::Size(86, 18);
            this->fcgLBMPGMuxerCmdEx->TabIndex = 24;
            this->fcgLBMPGMuxerCmdEx->Text = L"拡張オプション";
            // 
            // fcgCBMPGMuxerExt
            // 
            this->fcgCBMPGMuxerExt->AutoSize = true;
            this->fcgCBMPGMuxerExt->Location = System::Drawing::Point(14, 76);
            this->fcgCBMPGMuxerExt->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBMPGMuxerExt->Name = L"fcgCBMPGMuxerExt";
            this->fcgCBMPGMuxerExt->Size = System::Drawing::Size(141, 22);
            this->fcgCBMPGMuxerExt->TabIndex = 20;
            this->fcgCBMPGMuxerExt->Tag = L"chValue";
            this->fcgCBMPGMuxerExt->Text = L"外部muxerを使用";
            this->fcgCBMPGMuxerExt->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageMux
            // 
            this->fcgtabPageMux->Controls->Add(this->fcgCXMuxPriority);
            this->fcgtabPageMux->Controls->Add(this->fcgLBMuxPriority);
            this->fcgtabPageMux->Controls->Add(this->fcgCBMuxMinimize);
            this->fcgtabPageMux->Location = System::Drawing::Point(4, 27);
            this->fcgtabPageMux->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabPageMux->Name = L"fcgtabPageMux";
            this->fcgtabPageMux->Size = System::Drawing::Size(472, 220);
            this->fcgtabPageMux->TabIndex = 2;
            this->fcgtabPageMux->Text = L"Mux共通設定";
            this->fcgtabPageMux->UseVisualStyleBackColor = true;
            // 
            // fcgCXMuxPriority
            // 
            this->fcgCXMuxPriority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMuxPriority->FormattingEnabled = true;
            this->fcgCXMuxPriority->Location = System::Drawing::Point(128, 80);
            this->fcgCXMuxPriority->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXMuxPriority->Name = L"fcgCXMuxPriority";
            this->fcgCXMuxPriority->Size = System::Drawing::Size(246, 26);
            this->fcgCXMuxPriority->TabIndex = 1;
            this->fcgCXMuxPriority->Tag = L"chValue";
            // 
            // fcgLBMuxPriority
            // 
            this->fcgLBMuxPriority->AutoSize = true;
            this->fcgLBMuxPriority->Location = System::Drawing::Point(19, 84);
            this->fcgLBMuxPriority->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMuxPriority->Name = L"fcgLBMuxPriority";
            this->fcgLBMuxPriority->Size = System::Drawing::Size(79, 18);
            this->fcgLBMuxPriority->TabIndex = 1;
            this->fcgLBMuxPriority->Text = L"Mux優先度";
            // 
            // fcgCBMuxMinimize
            // 
            this->fcgCBMuxMinimize->AutoSize = true;
            this->fcgCBMuxMinimize->Location = System::Drawing::Point(22, 32);
            this->fcgCBMuxMinimize->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBMuxMinimize->Name = L"fcgCBMuxMinimize";
            this->fcgCBMuxMinimize->Size = System::Drawing::Size(72, 22);
            this->fcgCBMuxMinimize->TabIndex = 0;
            this->fcgCBMuxMinimize->Tag = L"chValue";
            this->fcgCBMuxMinimize->Text = L"最小化";
            this->fcgCBMuxMinimize->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageBat
            // 
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatAfterString);
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatBeforeString);
            this->fcgtabPageBat->Controls->Add(this->fcgPNSeparator);
            this->fcgtabPageBat->Controls->Add(this->fcgBTBatBeforePath);
            this->fcgtabPageBat->Controls->Add(this->fcgTXBatBeforePath);
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatBeforePath);
            this->fcgtabPageBat->Controls->Add(this->fcgCBWaitForBatBefore);
            this->fcgtabPageBat->Controls->Add(this->fcgCBRunBatBefore);
            this->fcgtabPageBat->Controls->Add(this->fcgBTBatAfterPath);
            this->fcgtabPageBat->Controls->Add(this->fcgTXBatAfterPath);
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatAfterPath);
            this->fcgtabPageBat->Controls->Add(this->fcgCBWaitForBatAfter);
            this->fcgtabPageBat->Controls->Add(this->fcgCBRunBatAfter);
            this->fcgtabPageBat->Location = System::Drawing::Point(4, 27);
            this->fcgtabPageBat->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabPageBat->Name = L"fcgtabPageBat";
            this->fcgtabPageBat->Size = System::Drawing::Size(472, 220);
            this->fcgtabPageBat->TabIndex = 3;
            this->fcgtabPageBat->Text = L"エンコ前後バッチ処理";
            this->fcgtabPageBat->UseVisualStyleBackColor = true;
            // 
            // fcgLBBatAfterString
            // 
            this->fcgLBBatAfterString->AutoSize = true;
            this->fcgLBBatAfterString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatAfterString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatAfterString->Location = System::Drawing::Point(380, 140);
            this->fcgLBBatAfterString->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatAfterString->Name = L"fcgLBBatAfterString";
            this->fcgLBBatAfterString->Size = System::Drawing::Size(34, 19);
            this->fcgLBBatAfterString->TabIndex = 20;
            this->fcgLBBatAfterString->Text = L" 後& ";
            this->fcgLBBatAfterString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgLBBatBeforeString
            // 
            this->fcgLBBatBeforeString->AutoSize = true;
            this->fcgLBBatBeforeString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatBeforeString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatBeforeString->Location = System::Drawing::Point(380, 18);
            this->fcgLBBatBeforeString->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatBeforeString->Name = L"fcgLBBatBeforeString";
            this->fcgLBBatBeforeString->Size = System::Drawing::Size(34, 19);
            this->fcgLBBatBeforeString->TabIndex = 19;
            this->fcgLBBatBeforeString->Text = L" 前& ";
            this->fcgLBBatBeforeString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgPNSeparator
            // 
            this->fcgPNSeparator->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->fcgPNSeparator->Location = System::Drawing::Point(22, 110);
            this->fcgPNSeparator->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNSeparator->Name = L"fcgPNSeparator";
            this->fcgPNSeparator->Size = System::Drawing::Size(427, 1);
            this->fcgPNSeparator->TabIndex = 18;
            // 
            // fcgBTBatBeforePath
            // 
            this->fcgBTBatBeforePath->Location = System::Drawing::Point(412, 69);
            this->fcgBTBatBeforePath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTBatBeforePath->Name = L"fcgBTBatBeforePath";
            this->fcgBTBatBeforePath->Size = System::Drawing::Size(38, 29);
            this->fcgBTBatBeforePath->TabIndex = 17;
            this->fcgBTBatBeforePath->Tag = L"chValue";
            this->fcgBTBatBeforePath->Text = L"...";
            this->fcgBTBatBeforePath->UseVisualStyleBackColor = true;
            this->fcgBTBatBeforePath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatBeforePath_Click);
            // 
            // fcgTXBatBeforePath
            // 
            this->fcgTXBatBeforePath->AllowDrop = true;
            this->fcgTXBatBeforePath->Location = System::Drawing::Point(158, 70);
            this->fcgTXBatBeforePath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXBatBeforePath->Name = L"fcgTXBatBeforePath";
            this->fcgTXBatBeforePath->Size = System::Drawing::Size(252, 25);
            this->fcgTXBatBeforePath->TabIndex = 16;
            this->fcgTXBatBeforePath->Tag = L"chValue";
            this->fcgTXBatBeforePath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatBeforePath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatBeforePath
            // 
            this->fcgLBBatBeforePath->AutoSize = true;
            this->fcgLBBatBeforePath->Location = System::Drawing::Point(50, 74);
            this->fcgLBBatBeforePath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatBeforePath->Name = L"fcgLBBatBeforePath";
            this->fcgLBBatBeforePath->Size = System::Drawing::Size(77, 18);
            this->fcgLBBatBeforePath->TabIndex = 15;
            this->fcgLBBatBeforePath->Text = L"バッチファイル";
            // 
            // fcgCBWaitForBatBefore
            // 
            this->fcgCBWaitForBatBefore->AutoSize = true;
            this->fcgCBWaitForBatBefore->Location = System::Drawing::Point(50, 38);
            this->fcgCBWaitForBatBefore->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBWaitForBatBefore->Name = L"fcgCBWaitForBatBefore";
            this->fcgCBWaitForBatBefore->Size = System::Drawing::Size(190, 22);
            this->fcgCBWaitForBatBefore->TabIndex = 14;
            this->fcgCBWaitForBatBefore->Tag = L"chValue";
            this->fcgCBWaitForBatBefore->Text = L"バッチ処理の終了を待機する";
            this->fcgCBWaitForBatBefore->UseVisualStyleBackColor = true;
            // 
            // fcgCBRunBatBefore
            // 
            this->fcgCBRunBatBefore->AutoSize = true;
            this->fcgCBRunBatBefore->Location = System::Drawing::Point(22, 8);
            this->fcgCBRunBatBefore->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBRunBatBefore->Name = L"fcgCBRunBatBefore";
            this->fcgCBRunBatBefore->Size = System::Drawing::Size(226, 22);
            this->fcgCBRunBatBefore->TabIndex = 13;
            this->fcgCBRunBatBefore->Tag = L"chValue";
            this->fcgCBRunBatBefore->Text = L"エンコード開始前、バッチ処理を行う";
            this->fcgCBRunBatBefore->UseVisualStyleBackColor = true;
            // 
            // fcgBTBatAfterPath
            // 
            this->fcgBTBatAfterPath->Location = System::Drawing::Point(412, 182);
            this->fcgBTBatAfterPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTBatAfterPath->Name = L"fcgBTBatAfterPath";
            this->fcgBTBatAfterPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTBatAfterPath->TabIndex = 10;
            this->fcgBTBatAfterPath->Tag = L"chValue";
            this->fcgBTBatAfterPath->Text = L"...";
            this->fcgBTBatAfterPath->UseVisualStyleBackColor = true;
            this->fcgBTBatAfterPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatAfterPath_Click);
            // 
            // fcgTXBatAfterPath
            // 
            this->fcgTXBatAfterPath->AllowDrop = true;
            this->fcgTXBatAfterPath->Location = System::Drawing::Point(158, 184);
            this->fcgTXBatAfterPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXBatAfterPath->Name = L"fcgTXBatAfterPath";
            this->fcgTXBatAfterPath->Size = System::Drawing::Size(252, 25);
            this->fcgTXBatAfterPath->TabIndex = 9;
            this->fcgTXBatAfterPath->Tag = L"chValue";
            this->fcgTXBatAfterPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatAfterPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatAfterPath
            // 
            this->fcgLBBatAfterPath->AutoSize = true;
            this->fcgLBBatAfterPath->Location = System::Drawing::Point(50, 188);
            this->fcgLBBatAfterPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatAfterPath->Name = L"fcgLBBatAfterPath";
            this->fcgLBBatAfterPath->Size = System::Drawing::Size(77, 18);
            this->fcgLBBatAfterPath->TabIndex = 8;
            this->fcgLBBatAfterPath->Text = L"バッチファイル";
            // 
            // fcgCBWaitForBatAfter
            // 
            this->fcgCBWaitForBatAfter->AutoSize = true;
            this->fcgCBWaitForBatAfter->Location = System::Drawing::Point(50, 152);
            this->fcgCBWaitForBatAfter->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBWaitForBatAfter->Name = L"fcgCBWaitForBatAfter";
            this->fcgCBWaitForBatAfter->Size = System::Drawing::Size(190, 22);
            this->fcgCBWaitForBatAfter->TabIndex = 7;
            this->fcgCBWaitForBatAfter->Tag = L"chValue";
            this->fcgCBWaitForBatAfter->Text = L"バッチ処理の終了を待機する";
            this->fcgCBWaitForBatAfter->UseVisualStyleBackColor = true;
            // 
            // fcgCBRunBatAfter
            // 
            this->fcgCBRunBatAfter->AutoSize = true;
            this->fcgCBRunBatAfter->Location = System::Drawing::Point(22, 122);
            this->fcgCBRunBatAfter->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBRunBatAfter->Name = L"fcgCBRunBatAfter";
            this->fcgCBRunBatAfter->Size = System::Drawing::Size(226, 22);
            this->fcgCBRunBatAfter->TabIndex = 6;
            this->fcgCBRunBatAfter->Tag = L"chValue";
            this->fcgCBRunBatAfter->Text = L"エンコード終了後、バッチ処理を行う";
            this->fcgCBRunBatAfter->UseVisualStyleBackColor = true;
            // 
            // fcgTXCmd
            // 
            this->fcgTXCmd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->fcgTXCmd->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgTXCmd->Location = System::Drawing::Point(11, 640);
            this->fcgTXCmd->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXCmd->Name = L"fcgTXCmd";
            this->fcgTXCmd->ReadOnly = true;
            this->fcgTXCmd->Size = System::Drawing::Size(1239, 25);
            this->fcgTXCmd->TabIndex = 4;
            this->fcgTXCmd->Visible = false;
            this->fcgTXCmd->DoubleClick += gcnew System::EventHandler(this, &frmConfig::fcgTXCmd_DoubleClick);
            // 
            // fcgBTCancel
            // 
            this->fcgBTCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->fcgBTCancel->Location = System::Drawing::Point(964, 682);
            this->fcgBTCancel->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTCancel->Name = L"fcgBTCancel";
            this->fcgBTCancel->Size = System::Drawing::Size(105, 35);
            this->fcgBTCancel->TabIndex = 5;
            this->fcgBTCancel->Text = L"キャンセル";
            this->fcgBTCancel->UseVisualStyleBackColor = true;
            this->fcgBTCancel->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTCancel_Click);
            // 
            // fcgBTOK
            // 
            this->fcgBTOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->fcgBTOK->Location = System::Drawing::Point(1116, 682);
            this->fcgBTOK->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTOK->Name = L"fcgBTOK";
            this->fcgBTOK->Size = System::Drawing::Size(105, 35);
            this->fcgBTOK->TabIndex = 6;
            this->fcgBTOK->Text = L"OK";
            this->fcgBTOK->UseVisualStyleBackColor = true;
            this->fcgBTOK->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTOK_Click);
            // 
            // fcgBTDefault
            // 
            this->fcgBTDefault->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgBTDefault->Location = System::Drawing::Point(11, 685);
            this->fcgBTDefault->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTDefault->Name = L"fcgBTDefault";
            this->fcgBTDefault->Size = System::Drawing::Size(140, 35);
            this->fcgBTDefault->TabIndex = 7;
            this->fcgBTDefault->Text = L"デフォルト";
            this->fcgBTDefault->UseVisualStyleBackColor = true;
            this->fcgBTDefault->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTDefault_Click);
            // 
            // fcgLBVersionDate
            // 
            this->fcgLBVersionDate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgLBVersionDate->AutoSize = true;
            this->fcgLBVersionDate->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBVersionDate->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBVersionDate->Location = System::Drawing::Point(556, 694);
            this->fcgLBVersionDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVersionDate->Name = L"fcgLBVersionDate";
            this->fcgLBVersionDate->Size = System::Drawing::Size(59, 18);
            this->fcgLBVersionDate->TabIndex = 8;
            this->fcgLBVersionDate->Text = L"Version";
            // 
            // fcgLBVersion
            // 
            this->fcgLBVersion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgLBVersion->AutoSize = true;
            this->fcgLBVersion->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBVersion->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBVersion->Location = System::Drawing::Point(170, 694);
            this->fcgLBVersion->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVersion->Name = L"fcgLBVersion";
            this->fcgLBVersion->Size = System::Drawing::Size(59, 18);
            this->fcgLBVersion->TabIndex = 9;
            this->fcgLBVersion->Text = L"Version";
            // 
            // fcgOpenFileDialog
            // 
            this->fcgOpenFileDialog->FileName = L"openFileDialog1";
            // 
            // fcgTTEx
            // 
            this->fcgTTEx->AutomaticDelay = 200;
            this->fcgTTEx->AutoPopDelay = 9999;
            this->fcgTTEx->InitialDelay = 200;
            this->fcgTTEx->IsBalloon = true;
            this->fcgTTEx->ReshowDelay = 50;
            this->fcgTTEx->ShowAlways = true;
            this->fcgTTEx->UseAnimation = false;
            this->fcgTTEx->UseFading = false;
            // 
            // fcgtabControlNVEnc
            // 
            this->fcgtabControlNVEnc->Controls->Add(this->tabPageVideoEnc);
            this->fcgtabControlNVEnc->Controls->Add(this->tabPageVideoDetail);
            this->fcgtabControlNVEnc->Controls->Add(this->tabPageExOpt);
            this->fcgtabControlNVEnc->Controls->Add(this->tabPageNVEncFeatures);
            this->fcgtabControlNVEnc->Location = System::Drawing::Point(5, 39);
            this->fcgtabControlNVEnc->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabControlNVEnc->Name = L"fcgtabControlNVEnc";
            this->fcgtabControlNVEnc->SelectedIndex = 0;
            this->fcgtabControlNVEnc->Size = System::Drawing::Size(770, 636);
            this->fcgtabControlNVEnc->TabIndex = 49;
            // 
            // tabPageVideoEnc
            // 
            this->tabPageVideoEnc->Controls->Add(this->fcgPNHEVC);
            this->tabPageVideoEnc->Controls->Add(this->fcgPNBitrate);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBWeightP);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBInterlaced);
            this->tabPageVideoEnc->Controls->Add(this->fcgCBWeightP);
            this->tabPageVideoEnc->Controls->Add(this->label3);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBLookaheadDisable);
            this->tabPageVideoEnc->Controls->Add(this->fcgNULookaheadDepth);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBAQStrengthAuto);
            this->tabPageVideoEnc->Controls->Add(this->fcgCXInterlaced);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUAQStrength);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBAQStrength);
            this->tabPageVideoEnc->Controls->Add(this->fcgCXAQ);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBLookaheadDepth);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBAQ);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUVBVBufsize);
            this->tabPageVideoEnc->Controls->Add(this->fcgGroupBoxAspectRatio);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBVBVBufsize);
            this->tabPageVideoEnc->Controls->Add(this->fcgCBAFS);
            this->tabPageVideoEnc->Controls->Add(this->label1);
            this->tabPageVideoEnc->Controls->Add(this->fcgCXEncCodec);
            this->tabPageVideoEnc->Controls->Add(this->fcgNURefFrames);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBRefFrames);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUBframes);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBBframes);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBGOPLengthAuto);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUGopLength);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBGOPLength);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBEncMode);
            this->tabPageVideoEnc->Controls->Add(this->fcgCXEncMode);
            this->tabPageVideoEnc->Controls->Add(this->fcgPBNVEncLogoEnabled);
            this->tabPageVideoEnc->Controls->Add(this->fcgPBNVEncLogoDisabled);
            this->tabPageVideoEnc->Controls->Add(this->fcgPNH264);
            this->tabPageVideoEnc->Controls->Add(this->fcgPNQP);
            this->tabPageVideoEnc->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->tabPageVideoEnc->Location = System::Drawing::Point(4, 28);
            this->tabPageVideoEnc->Margin = System::Windows::Forms::Padding(4);
            this->tabPageVideoEnc->Name = L"tabPageVideoEnc";
            this->tabPageVideoEnc->Padding = System::Windows::Forms::Padding(4);
            this->tabPageVideoEnc->Size = System::Drawing::Size(762, 604);
            this->tabPageVideoEnc->TabIndex = 0;
            this->tabPageVideoEnc->Text = L"動画エンコード";
            this->tabPageVideoEnc->UseVisualStyleBackColor = true;
            // 
            // fcgPNHEVC
            // 
            this->fcgPNHEVC->Controls->Add(this->fcgLBHEVCOutBitDepth);
            this->fcgPNHEVC->Controls->Add(this->fcgCXHEVCOutBitDepth);
            this->fcgPNHEVC->Controls->Add(this->fcgLBFullrangeHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgCBFullrangeHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgCXVideoFormatHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgLBVideoFormatHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcggroupBoxColorHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgLBHEVCProfile);
            this->fcgPNHEVC->Controls->Add(this->fxgLBHEVCTier);
            this->fcgPNHEVC->Controls->Add(this->fcgCXHEVCTier);
            this->fcgPNHEVC->Controls->Add(this->fxgCXHEVCLevel);
            this->fcgPNHEVC->Location = System::Drawing::Point(426, 206);
            this->fcgPNHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNHEVC->Name = L"fcgPNHEVC";
            this->fcgPNHEVC->Size = System::Drawing::Size(330, 384);
            this->fcgPNHEVC->TabIndex = 153;
            // 
            // fcgLBHEVCOutBitDepth
            // 
            this->fcgLBHEVCOutBitDepth->AutoSize = true;
            this->fcgLBHEVCOutBitDepth->Location = System::Drawing::Point(19, 9);
            this->fcgLBHEVCOutBitDepth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBHEVCOutBitDepth->Name = L"fcgLBHEVCOutBitDepth";
            this->fcgLBHEVCOutBitDepth->Size = System::Drawing::Size(92, 18);
            this->fcgLBHEVCOutBitDepth->TabIndex = 156;
            this->fcgLBHEVCOutBitDepth->Text = L"出力ビット深度";
            // 
            // fcgCXHEVCOutBitDepth
            // 
            this->fcgCXHEVCOutBitDepth->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCOutBitDepth->FormattingEnabled = true;
            this->fcgCXHEVCOutBitDepth->Location = System::Drawing::Point(158, 6);
            this->fcgCXHEVCOutBitDepth->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXHEVCOutBitDepth->Name = L"fcgCXHEVCOutBitDepth";
            this->fcgCXHEVCOutBitDepth->Size = System::Drawing::Size(150, 26);
            this->fcgCXHEVCOutBitDepth->TabIndex = 80;
            this->fcgCXHEVCOutBitDepth->Tag = L"chValue";
            // 
            // fcgLBFullrangeHEVC
            // 
            this->fcgLBFullrangeHEVC->AutoSize = true;
            this->fcgLBFullrangeHEVC->Location = System::Drawing::Point(24, 228);
            this->fcgLBFullrangeHEVC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBFullrangeHEVC->Name = L"fcgLBFullrangeHEVC";
            this->fcgLBFullrangeHEVC->Size = System::Drawing::Size(69, 18);
            this->fcgLBFullrangeHEVC->TabIndex = 154;
            this->fcgLBFullrangeHEVC->Text = L"fullrange";
            // 
            // fcgCBFullrangeHEVC
            // 
            this->fcgCBFullrangeHEVC->AutoSize = true;
            this->fcgCBFullrangeHEVC->Location = System::Drawing::Point(158, 232);
            this->fcgCBFullrangeHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBFullrangeHEVC->Name = L"fcgCBFullrangeHEVC";
            this->fcgCBFullrangeHEVC->Size = System::Drawing::Size(18, 17);
            this->fcgCBFullrangeHEVC->TabIndex = 91;
            this->fcgCBFullrangeHEVC->Tag = L"chValue";
            this->fcgCBFullrangeHEVC->UseVisualStyleBackColor = true;
            // 
            // fcgCXVideoFormatHEVC
            // 
            this->fcgCXVideoFormatHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVideoFormatHEVC->FormattingEnabled = true;
            this->fcgCXVideoFormatHEVC->Location = System::Drawing::Point(158, 194);
            this->fcgCXVideoFormatHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXVideoFormatHEVC->Name = L"fcgCXVideoFormatHEVC";
            this->fcgCXVideoFormatHEVC->Size = System::Drawing::Size(150, 26);
            this->fcgCXVideoFormatHEVC->TabIndex = 90;
            this->fcgCXVideoFormatHEVC->Tag = L"chValue";
            // 
            // fcgLBVideoFormatHEVC
            // 
            this->fcgLBVideoFormatHEVC->AutoSize = true;
            this->fcgLBVideoFormatHEVC->Location = System::Drawing::Point(24, 196);
            this->fcgLBVideoFormatHEVC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVideoFormatHEVC->Name = L"fcgLBVideoFormatHEVC";
            this->fcgLBVideoFormatHEVC->Size = System::Drawing::Size(90, 18);
            this->fcgLBVideoFormatHEVC->TabIndex = 153;
            this->fcgLBVideoFormatHEVC->Text = L"videoformat";
            // 
            // fcggroupBoxColorHEVC
            // 
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgCXTransferHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgCXColorPrimHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgCXColorMatrixHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgLBTransferHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgLBColorPrimHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgLBColorMatrixHEVC);
            this->fcggroupBoxColorHEVC->Location = System::Drawing::Point(19, 252);
            this->fcggroupBoxColorHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxColorHEVC->Name = L"fcggroupBoxColorHEVC";
            this->fcggroupBoxColorHEVC->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxColorHEVC->Size = System::Drawing::Size(301, 129);
            this->fcggroupBoxColorHEVC->TabIndex = 92;
            this->fcggroupBoxColorHEVC->TabStop = false;
            this->fcggroupBoxColorHEVC->Text = L"色設定";
            // 
            // fcgCXTransferHEVC
            // 
            this->fcgCXTransferHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXTransferHEVC->FormattingEnabled = true;
            this->fcgCXTransferHEVC->Location = System::Drawing::Point(139, 90);
            this->fcgCXTransferHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXTransferHEVC->Name = L"fcgCXTransferHEVC";
            this->fcgCXTransferHEVC->Size = System::Drawing::Size(150, 26);
            this->fcgCXTransferHEVC->TabIndex = 2;
            this->fcgCXTransferHEVC->Tag = L"chValue";
            // 
            // fcgCXColorPrimHEVC
            // 
            this->fcgCXColorPrimHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorPrimHEVC->FormattingEnabled = true;
            this->fcgCXColorPrimHEVC->Location = System::Drawing::Point(139, 55);
            this->fcgCXColorPrimHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXColorPrimHEVC->Name = L"fcgCXColorPrimHEVC";
            this->fcgCXColorPrimHEVC->Size = System::Drawing::Size(150, 26);
            this->fcgCXColorPrimHEVC->TabIndex = 1;
            this->fcgCXColorPrimHEVC->Tag = L"chValue";
            // 
            // fcgCXColorMatrixHEVC
            // 
            this->fcgCXColorMatrixHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorMatrixHEVC->FormattingEnabled = true;
            this->fcgCXColorMatrixHEVC->Location = System::Drawing::Point(139, 20);
            this->fcgCXColorMatrixHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXColorMatrixHEVC->Name = L"fcgCXColorMatrixHEVC";
            this->fcgCXColorMatrixHEVC->Size = System::Drawing::Size(150, 26);
            this->fcgCXColorMatrixHEVC->TabIndex = 0;
            this->fcgCXColorMatrixHEVC->Tag = L"chValue";
            // 
            // fcgLBTransferHEVC
            // 
            this->fcgLBTransferHEVC->AutoSize = true;
            this->fcgLBTransferHEVC->Location = System::Drawing::Point(22, 94);
            this->fcgLBTransferHEVC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBTransferHEVC->Name = L"fcgLBTransferHEVC";
            this->fcgLBTransferHEVC->Size = System::Drawing::Size(62, 18);
            this->fcgLBTransferHEVC->TabIndex = 2;
            this->fcgLBTransferHEVC->Text = L"transfer";
            // 
            // fcgLBColorPrimHEVC
            // 
            this->fcgLBColorPrimHEVC->AutoSize = true;
            this->fcgLBColorPrimHEVC->Location = System::Drawing::Point(22, 59);
            this->fcgLBColorPrimHEVC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBColorPrimHEVC->Name = L"fcgLBColorPrimHEVC";
            this->fcgLBColorPrimHEVC->Size = System::Drawing::Size(73, 18);
            this->fcgLBColorPrimHEVC->TabIndex = 1;
            this->fcgLBColorPrimHEVC->Text = L"colorprim";
            // 
            // fcgLBColorMatrixHEVC
            // 
            this->fcgLBColorMatrixHEVC->AutoSize = true;
            this->fcgLBColorMatrixHEVC->Location = System::Drawing::Point(22, 24);
            this->fcgLBColorMatrixHEVC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBColorMatrixHEVC->Name = L"fcgLBColorMatrixHEVC";
            this->fcgLBColorMatrixHEVC->Size = System::Drawing::Size(85, 18);
            this->fcgLBColorMatrixHEVC->TabIndex = 0;
            this->fcgLBColorMatrixHEVC->Text = L"colormatrix";
            // 
            // fcgLBHEVCProfile
            // 
            this->fcgLBHEVCProfile->AutoSize = true;
            this->fcgLBHEVCProfile->Location = System::Drawing::Point(19, 48);
            this->fcgLBHEVCProfile->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBHEVCProfile->Name = L"fcgLBHEVCProfile";
            this->fcgLBHEVCProfile->Size = System::Drawing::Size(67, 18);
            this->fcgLBHEVCProfile->TabIndex = 83;
            this->fcgLBHEVCProfile->Text = L"プロファイル";
            // 
            // fxgLBHEVCTier
            // 
            this->fxgLBHEVCTier->AutoSize = true;
            this->fxgLBHEVCTier->Location = System::Drawing::Point(19, 85);
            this->fxgLBHEVCTier->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fxgLBHEVCTier->Name = L"fxgLBHEVCTier";
            this->fxgLBHEVCTier->Size = System::Drawing::Size(41, 18);
            this->fxgLBHEVCTier->TabIndex = 84;
            this->fxgLBHEVCTier->Text = L"レベル";
            // 
            // fcgCXHEVCTier
            // 
            this->fcgCXHEVCTier->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCTier->FormattingEnabled = true;
            this->fcgCXHEVCTier->Location = System::Drawing::Point(158, 44);
            this->fcgCXHEVCTier->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXHEVCTier->Name = L"fcgCXHEVCTier";
            this->fcgCXHEVCTier->Size = System::Drawing::Size(150, 26);
            this->fcgCXHEVCTier->TabIndex = 81;
            this->fcgCXHEVCTier->Tag = L"chValue";
            // 
            // fxgCXHEVCLevel
            // 
            this->fxgCXHEVCLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fxgCXHEVCLevel->FormattingEnabled = true;
            this->fxgCXHEVCLevel->Location = System::Drawing::Point(158, 81);
            this->fxgCXHEVCLevel->Margin = System::Windows::Forms::Padding(4);
            this->fxgCXHEVCLevel->Name = L"fxgCXHEVCLevel";
            this->fxgCXHEVCLevel->Size = System::Drawing::Size(150, 26);
            this->fxgCXHEVCLevel->TabIndex = 82;
            this->fxgCXHEVCLevel->Tag = L"chValue";
            // 
            // fcgPNBitrate
            // 
            this->fcgPNBitrate->Controls->Add(this->fcgLBVBRTragetQuality2);
            this->fcgPNBitrate->Controls->Add(this->fcgNUVBRTragetQuality);
            this->fcgPNBitrate->Controls->Add(this->fcgLBVBRTragetQuality);
            this->fcgPNBitrate->Controls->Add(this->fcgLBBitrate);
            this->fcgPNBitrate->Controls->Add(this->fcgNUBitrate);
            this->fcgPNBitrate->Controls->Add(this->fcgLBBitrate2);
            this->fcgPNBitrate->Controls->Add(this->fcgNUMaxkbps);
            this->fcgPNBitrate->Controls->Add(this->fcgLBMaxkbps);
            this->fcgPNBitrate->Controls->Add(this->fcgLBMaxBitrate2);
            this->fcgPNBitrate->Location = System::Drawing::Point(10, 175);
            this->fcgPNBitrate->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNBitrate->Name = L"fcgPNBitrate";
            this->fcgPNBitrate->Size = System::Drawing::Size(361, 99);
            this->fcgPNBitrate->TabIndex = 114;
            // 
            // fcgLBVBRTragetQuality2
            // 
            this->fcgLBVBRTragetQuality2->AutoSize = true;
            this->fcgLBVBRTragetQuality2->Location = System::Drawing::Point(259, 71);
            this->fcgLBVBRTragetQuality2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVBRTragetQuality2->Name = L"fcgLBVBRTragetQuality2";
            this->fcgLBVBRTragetQuality2->Size = System::Drawing::Size(82, 18);
            this->fcgLBVBRTragetQuality2->TabIndex = 102;
            this->fcgLBVBRTragetQuality2->Text = L"※\"0\"で自動";
            // 
            // fcgNUVBRTragetQuality
            // 
            this->fcgNUVBRTragetQuality->DecimalPlaces = 2;
            this->fcgNUVBRTragetQuality->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
            this->fcgNUVBRTragetQuality->Location = System::Drawing::Point(155, 69);
            this->fcgNUVBRTragetQuality->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVBRTragetQuality->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUVBRTragetQuality->Name = L"fcgNUVBRTragetQuality";
            this->fcgNUVBRTragetQuality->Size = System::Drawing::Size(96, 25);
            this->fcgNUVBRTragetQuality->TabIndex = 81;
            this->fcgNUVBRTragetQuality->Tag = L"chValue";
            this->fcgNUVBRTragetQuality->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBVBRTragetQuality
            // 
            this->fcgLBVBRTragetQuality->AutoSize = true;
            this->fcgLBVBRTragetQuality->Location = System::Drawing::Point(6, 74);
            this->fcgLBVBRTragetQuality->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVBRTragetQuality->Name = L"fcgLBVBRTragetQuality";
            this->fcgLBVBRTragetQuality->Size = System::Drawing::Size(93, 18);
            this->fcgLBVBRTragetQuality->TabIndex = 82;
            this->fcgLBVBRTragetQuality->Text = L"VBR品質目標";
            // 
            // fcgLBBitrate
            // 
            this->fcgLBBitrate->AutoSize = true;
            this->fcgLBBitrate->Location = System::Drawing::Point(6, 5);
            this->fcgLBBitrate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBitrate->Name = L"fcgLBBitrate";
            this->fcgLBBitrate->Size = System::Drawing::Size(68, 18);
            this->fcgLBBitrate->TabIndex = 66;
            this->fcgLBBitrate->Text = L"ビットレート";
            // 
            // fcgNUBitrate
            // 
            this->fcgNUBitrate->Location = System::Drawing::Point(155, 2);
            this->fcgNUBitrate->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUBitrate->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUBitrate->Name = L"fcgNUBitrate";
            this->fcgNUBitrate->Size = System::Drawing::Size(96, 25);
            this->fcgNUBitrate->TabIndex = 2;
            this->fcgNUBitrate->Tag = L"chValue";
            this->fcgNUBitrate->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBBitrate2
            // 
            this->fcgLBBitrate2->AutoSize = true;
            this->fcgLBBitrate2->Location = System::Drawing::Point(259, 5);
            this->fcgLBBitrate2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBitrate2->Name = L"fcgLBBitrate2";
            this->fcgLBBitrate2->Size = System::Drawing::Size(41, 18);
            this->fcgLBBitrate2->TabIndex = 69;
            this->fcgLBBitrate2->Text = L"kbps";
            // 
            // fcgNUMaxkbps
            // 
            this->fcgNUMaxkbps->Location = System::Drawing::Point(155, 36);
            this->fcgNUMaxkbps->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUMaxkbps->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUMaxkbps->Name = L"fcgNUMaxkbps";
            this->fcgNUMaxkbps->Size = System::Drawing::Size(96, 25);
            this->fcgNUMaxkbps->TabIndex = 3;
            this->fcgNUMaxkbps->Tag = L"chValue";
            this->fcgNUMaxkbps->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBMaxkbps
            // 
            this->fcgLBMaxkbps->AutoSize = true;
            this->fcgLBMaxkbps->Location = System::Drawing::Point(6, 41);
            this->fcgLBMaxkbps->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMaxkbps->Name = L"fcgLBMaxkbps";
            this->fcgLBMaxkbps->Size = System::Drawing::Size(96, 18);
            this->fcgLBMaxkbps->TabIndex = 78;
            this->fcgLBMaxkbps->Text = L"最大ビットレート";
            // 
            // fcgLBMaxBitrate2
            // 
            this->fcgLBMaxBitrate2->AutoSize = true;
            this->fcgLBMaxBitrate2->Location = System::Drawing::Point(259, 39);
            this->fcgLBMaxBitrate2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMaxBitrate2->Name = L"fcgLBMaxBitrate2";
            this->fcgLBMaxBitrate2->Size = System::Drawing::Size(41, 18);
            this->fcgLBMaxBitrate2->TabIndex = 80;
            this->fcgLBMaxBitrate2->Text = L"kbps";
            // 
            // fcgLBWeightP
            // 
            this->fcgLBWeightP->AutoSize = true;
            this->fcgLBWeightP->Location = System::Drawing::Point(19, 541);
            this->fcgLBWeightP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBWeightP->Name = L"fcgLBWeightP";
            this->fcgLBWeightP->Size = System::Drawing::Size(109, 18);
            this->fcgLBWeightP->TabIndex = 169;
            this->fcgLBWeightP->Text = L"重み付きPフレーム";
            // 
            // fcgLBInterlaced
            // 
            this->fcgLBInterlaced->AutoSize = true;
            this->fcgLBInterlaced->Location = System::Drawing::Point(446, 178);
            this->fcgLBInterlaced->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBInterlaced->Name = L"fcgLBInterlaced";
            this->fcgLBInterlaced->Size = System::Drawing::Size(109, 18);
            this->fcgLBInterlaced->TabIndex = 86;
            this->fcgLBInterlaced->Text = L"入力フレームタイプ";
            // 
            // fcgCBWeightP
            // 
            this->fcgCBWeightP->AutoSize = true;
            this->fcgCBWeightP->Location = System::Drawing::Point(165, 542);
            this->fcgCBWeightP->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBWeightP->Name = L"fcgCBWeightP";
            this->fcgCBWeightP->Size = System::Drawing::Size(18, 17);
            this->fcgCBWeightP->TabIndex = 17;
            this->fcgCBWeightP->Tag = L"chValue";
            this->fcgCBWeightP->UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(269, 391);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(41, 18);
            this->label3->TabIndex = 167;
            this->label3->Text = L"kbps";
            // 
            // fcgLBLookaheadDisable
            // 
            this->fcgLBLookaheadDisable->AutoSize = true;
            this->fcgLBLookaheadDisable->Location = System::Drawing::Point(269, 425);
            this->fcgLBLookaheadDisable->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBLookaheadDisable->Name = L"fcgLBLookaheadDisable";
            this->fcgLBLookaheadDisable->Size = System::Drawing::Size(82, 18);
            this->fcgLBLookaheadDisable->TabIndex = 165;
            this->fcgLBLookaheadDisable->Text = L"※\"0\"で無効";
            // 
            // fcgNULookaheadDepth
            // 
            this->fcgNULookaheadDepth->Location = System::Drawing::Point(165, 422);
            this->fcgNULookaheadDepth->Margin = System::Windows::Forms::Padding(4);
            this->fcgNULookaheadDepth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 32, 0, 0, 0 });
            this->fcgNULookaheadDepth->Name = L"fcgNULookaheadDepth";
            this->fcgNULookaheadDepth->Size = System::Drawing::Size(96, 25);
            this->fcgNULookaheadDepth->TabIndex = 14;
            this->fcgNULookaheadDepth->Tag = L"chValue";
            this->fcgNULookaheadDepth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBAQStrengthAuto
            // 
            this->fcgLBAQStrengthAuto->AutoSize = true;
            this->fcgLBAQStrengthAuto->Location = System::Drawing::Point(269, 500);
            this->fcgLBAQStrengthAuto->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAQStrengthAuto->Name = L"fcgLBAQStrengthAuto";
            this->fcgLBAQStrengthAuto->Size = System::Drawing::Size(82, 18);
            this->fcgLBAQStrengthAuto->TabIndex = 163;
            this->fcgLBAQStrengthAuto->Text = L"※\"0\"で自動";
            // 
            // fcgCXInterlaced
            // 
            this->fcgCXInterlaced->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXInterlaced->FormattingEnabled = true;
            this->fcgCXInterlaced->Location = System::Drawing::Point(585, 172);
            this->fcgCXInterlaced->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXInterlaced->Name = L"fcgCXInterlaced";
            this->fcgCXInterlaced->Size = System::Drawing::Size(150, 26);
            this->fcgCXInterlaced->TabIndex = 40;
            this->fcgCXInterlaced->Tag = L"chValue";
            // 
            // fcgNUAQStrength
            // 
            this->fcgNUAQStrength->Location = System::Drawing::Point(165, 498);
            this->fcgNUAQStrength->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUAQStrength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
            this->fcgNUAQStrength->Name = L"fcgNUAQStrength";
            this->fcgNUAQStrength->Size = System::Drawing::Size(96, 25);
            this->fcgNUAQStrength->TabIndex = 16;
            this->fcgNUAQStrength->Tag = L"chValue";
            this->fcgNUAQStrength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBAQStrength
            // 
            this->fcgLBAQStrength->AutoSize = true;
            this->fcgLBAQStrength->Location = System::Drawing::Point(18, 500);
            this->fcgLBAQStrength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAQStrength->Name = L"fcgLBAQStrength";
            this->fcgLBAQStrength->Size = System::Drawing::Size(135, 18);
            this->fcgLBAQStrength->TabIndex = 162;
            this->fcgLBAQStrength->Text = L"AQstrength (1-15)";
            // 
            // fcgCXAQ
            // 
            this->fcgCXAQ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAQ->FormattingEnabled = true;
            this->fcgCXAQ->Location = System::Drawing::Point(165, 459);
            this->fcgCXAQ->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAQ->Name = L"fcgCXAQ";
            this->fcgCXAQ->Size = System::Drawing::Size(152, 26);
            this->fcgCXAQ->TabIndex = 15;
            this->fcgCXAQ->Tag = L"chValue";
            // 
            // fcgLBLookaheadDepth
            // 
            this->fcgLBLookaheadDepth->AutoSize = true;
            this->fcgLBLookaheadDepth->Location = System::Drawing::Point(18, 425);
            this->fcgLBLookaheadDepth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBLookaheadDepth->Name = L"fcgLBLookaheadDepth";
            this->fcgLBLookaheadDepth->Size = System::Drawing::Size(127, 18);
            this->fcgLBLookaheadDepth->TabIndex = 160;
            this->fcgLBLookaheadDepth->Text = L"Lookahead depth";
            // 
            // fcgLBAQ
            // 
            this->fcgLBAQ->AutoSize = true;
            this->fcgLBAQ->Location = System::Drawing::Point(18, 462);
            this->fcgLBAQ->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAQ->Name = L"fcgLBAQ";
            this->fcgLBAQ->Size = System::Drawing::Size(129, 18);
            this->fcgLBAQ->TabIndex = 158;
            this->fcgLBAQ->Text = L"適応的量子化 (AQ)";
            // 
            // fcgNUVBVBufsize
            // 
            this->fcgNUVBVBufsize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
            this->fcgNUVBVBufsize->Location = System::Drawing::Point(165, 386);
            this->fcgNUVBVBufsize->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVBVBufsize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128000, 0, 0, 0 });
            this->fcgNUVBVBufsize->Name = L"fcgNUVBVBufsize";
            this->fcgNUVBVBufsize->Size = System::Drawing::Size(96, 25);
            this->fcgNUVBVBufsize->TabIndex = 13;
            this->fcgNUVBVBufsize->Tag = L"chValue";
            this->fcgNUVBVBufsize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgGroupBoxAspectRatio
            // 
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgLBAspectRatio);
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgNUAspectRatioY);
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgNUAspectRatioX);
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgCXAspectRatio);
            this->fcgGroupBoxAspectRatio->Location = System::Drawing::Point(441, 54);
            this->fcgGroupBoxAspectRatio->Margin = System::Windows::Forms::Padding(4);
            this->fcgGroupBoxAspectRatio->Name = L"fcgGroupBoxAspectRatio";
            this->fcgGroupBoxAspectRatio->Padding = System::Windows::Forms::Padding(4);
            this->fcgGroupBoxAspectRatio->Size = System::Drawing::Size(301, 95);
            this->fcgGroupBoxAspectRatio->TabIndex = 31;
            this->fcgGroupBoxAspectRatio->TabStop = false;
            this->fcgGroupBoxAspectRatio->Text = L"アスペクト比";
            // 
            // fcgLBAspectRatio
            // 
            this->fcgLBAspectRatio->AutoSize = true;
            this->fcgLBAspectRatio->Location = System::Drawing::Point(164, 59);
            this->fcgLBAspectRatio->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAspectRatio->Name = L"fcgLBAspectRatio";
            this->fcgLBAspectRatio->Size = System::Drawing::Size(14, 18);
            this->fcgLBAspectRatio->TabIndex = 3;
            this->fcgLBAspectRatio->Text = L":";
            // 
            // fcgNUAspectRatioY
            // 
            this->fcgNUAspectRatioY->Location = System::Drawing::Point(186, 56);
            this->fcgNUAspectRatioY->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUAspectRatioY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUAspectRatioY->Name = L"fcgNUAspectRatioY";
            this->fcgNUAspectRatioY->Size = System::Drawing::Size(75, 25);
            this->fcgNUAspectRatioY->TabIndex = 2;
            this->fcgNUAspectRatioY->Tag = L"chValue";
            this->fcgNUAspectRatioY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUAspectRatioX
            // 
            this->fcgNUAspectRatioX->Location = System::Drawing::Point(81, 56);
            this->fcgNUAspectRatioX->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUAspectRatioX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUAspectRatioX->Name = L"fcgNUAspectRatioX";
            this->fcgNUAspectRatioX->Size = System::Drawing::Size(75, 25);
            this->fcgNUAspectRatioX->TabIndex = 1;
            this->fcgNUAspectRatioX->Tag = L"chValue";
            this->fcgNUAspectRatioX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgCXAspectRatio
            // 
            this->fcgCXAspectRatio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAspectRatio->FormattingEnabled = true;
            this->fcgCXAspectRatio->Location = System::Drawing::Point(32, 22);
            this->fcgCXAspectRatio->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAspectRatio->Name = L"fcgCXAspectRatio";
            this->fcgCXAspectRatio->Size = System::Drawing::Size(245, 26);
            this->fcgCXAspectRatio->TabIndex = 0;
            this->fcgCXAspectRatio->Tag = L"chValue";
            // 
            // fcgLBVBVBufsize
            // 
            this->fcgLBVBVBufsize->AutoSize = true;
            this->fcgLBVBVBufsize->Location = System::Drawing::Point(18, 388);
            this->fcgLBVBVBufsize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVBVBufsize->Name = L"fcgLBVBVBufsize";
            this->fcgLBVBVBufsize->Size = System::Drawing::Size(106, 18);
            this->fcgLBVBVBufsize->TabIndex = 156;
            this->fcgLBVBVBufsize->Text = L"VBVバッファサイズ";
            // 
            // fcgCBAFS
            // 
            this->fcgCBAFS->AutoSize = true;
            this->fcgCBAFS->Location = System::Drawing::Point(452, 20);
            this->fcgCBAFS->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBAFS->Name = L"fcgCBAFS";
            this->fcgCBAFS->Size = System::Drawing::Size(231, 22);
            this->fcgCBAFS->TabIndex = 30;
            this->fcgCBAFS->Tag = L"chValue";
            this->fcgCBAFS->Text = L"自動フィールドシフト(afs)を使用する";
            this->fcgCBAFS->UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(16, 110);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(64, 18);
            this->label1->TabIndex = 151;
            this->label1->Text = L"出力形式";
            // 
            // fcgCXEncCodec
            // 
            this->fcgCXEncCodec->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXEncCodec->FormattingEnabled = true;
            this->fcgCXEncCodec->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"高品質", L"標準", L"高速" });
            this->fcgCXEncCodec->Location = System::Drawing::Point(101, 106);
            this->fcgCXEncCodec->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXEncCodec->Name = L"fcgCXEncCodec";
            this->fcgCXEncCodec->Size = System::Drawing::Size(230, 26);
            this->fcgCXEncCodec->TabIndex = 0;
            this->fcgCXEncCodec->Tag = L"chValue";
            this->fcgCXEncCodec->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcgNURefFrames
            // 
            this->fcgNURefFrames->Location = System::Drawing::Point(165, 351);
            this->fcgNURefFrames->Margin = System::Windows::Forms::Padding(4);
            this->fcgNURefFrames->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
            this->fcgNURefFrames->Name = L"fcgNURefFrames";
            this->fcgNURefFrames->Size = System::Drawing::Size(96, 25);
            this->fcgNURefFrames->TabIndex = 12;
            this->fcgNURefFrames->Tag = L"chValue";
            this->fcgNURefFrames->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBRefFrames
            // 
            this->fcgLBRefFrames->AutoSize = true;
            this->fcgLBRefFrames->Location = System::Drawing::Point(16, 354);
            this->fcgLBRefFrames->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBRefFrames->Name = L"fcgLBRefFrames";
            this->fcgLBRefFrames->Size = System::Drawing::Size(64, 18);
            this->fcgLBRefFrames->TabIndex = 140;
            this->fcgLBRefFrames->Text = L"参照距離";
            // 
            // fcgNUBframes
            // 
            this->fcgNUBframes->Location = System::Drawing::Point(165, 316);
            this->fcgNUBframes->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUBframes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
            this->fcgNUBframes->Name = L"fcgNUBframes";
            this->fcgNUBframes->Size = System::Drawing::Size(96, 25);
            this->fcgNUBframes->TabIndex = 11;
            this->fcgNUBframes->Tag = L"chValue";
            this->fcgNUBframes->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBBframes
            // 
            this->fcgLBBframes->AutoSize = true;
            this->fcgLBBframes->Location = System::Drawing::Point(18, 320);
            this->fcgLBBframes->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBframes->Name = L"fcgLBBframes";
            this->fcgLBBframes->Size = System::Drawing::Size(73, 18);
            this->fcgLBBframes->TabIndex = 133;
            this->fcgLBBframes->Text = L"Bフレーム数";
            // 
            // fcgLBGOPLengthAuto
            // 
            this->fcgLBGOPLengthAuto->AutoSize = true;
            this->fcgLBGOPLengthAuto->Location = System::Drawing::Point(268, 285);
            this->fcgLBGOPLengthAuto->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBGOPLengthAuto->Name = L"fcgLBGOPLengthAuto";
            this->fcgLBGOPLengthAuto->Size = System::Drawing::Size(82, 18);
            this->fcgLBGOPLengthAuto->TabIndex = 101;
            this->fcgLBGOPLengthAuto->Text = L"※\"0\"で自動";
            // 
            // fcgNUGopLength
            // 
            this->fcgNUGopLength->Location = System::Drawing::Point(165, 281);
            this->fcgNUGopLength->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUGopLength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 120000, 0, 0, 0 });
            this->fcgNUGopLength->Name = L"fcgNUGopLength";
            this->fcgNUGopLength->Size = System::Drawing::Size(96, 25);
            this->fcgNUGopLength->TabIndex = 10;
            this->fcgNUGopLength->Tag = L"chValue";
            this->fcgNUGopLength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBGOPLength
            // 
            this->fcgLBGOPLength->AutoSize = true;
            this->fcgLBGOPLength->Location = System::Drawing::Point(18, 285);
            this->fcgLBGOPLength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBGOPLength->Name = L"fcgLBGOPLength";
            this->fcgLBGOPLength->Size = System::Drawing::Size(51, 18);
            this->fcgLBGOPLength->TabIndex = 85;
            this->fcgLBGOPLength->Text = L"GOP長";
            // 
            // fcgLBEncMode
            // 
            this->fcgLBEncMode->AutoSize = true;
            this->fcgLBEncMode->Location = System::Drawing::Point(16, 145);
            this->fcgLBEncMode->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBEncMode->Name = L"fcgLBEncMode";
            this->fcgLBEncMode->Size = System::Drawing::Size(40, 18);
            this->fcgLBEncMode->TabIndex = 79;
            this->fcgLBEncMode->Text = L"モード";
            // 
            // fcgCXEncMode
            // 
            this->fcgCXEncMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXEncMode->FormattingEnabled = true;
            this->fcgCXEncMode->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"高品質", L"標準", L"高速" });
            this->fcgCXEncMode->Location = System::Drawing::Point(101, 141);
            this->fcgCXEncMode->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXEncMode->Name = L"fcgCXEncMode";
            this->fcgCXEncMode->Size = System::Drawing::Size(230, 26);
            this->fcgCXEncMode->TabIndex = 1;
            this->fcgCXEncMode->Tag = L"chValue";
            this->fcgCXEncMode->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcgPBNVEncLogoEnabled
            // 
            this->fcgPBNVEncLogoEnabled->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgPBNVEncLogoEnabled.Image")));
            this->fcgPBNVEncLogoEnabled->Location = System::Drawing::Point(8, 4);
            this->fcgPBNVEncLogoEnabled->Margin = System::Windows::Forms::Padding(4);
            this->fcgPBNVEncLogoEnabled->Name = L"fcgPBNVEncLogoEnabled";
            this->fcgPBNVEncLogoEnabled->Size = System::Drawing::Size(274, 94);
            this->fcgPBNVEncLogoEnabled->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->fcgPBNVEncLogoEnabled->TabIndex = 148;
            this->fcgPBNVEncLogoEnabled->TabStop = false;
            // 
            // fcgPBNVEncLogoDisabled
            // 
            this->fcgPBNVEncLogoDisabled->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgPBNVEncLogoDisabled.Image")));
            this->fcgPBNVEncLogoDisabled->Location = System::Drawing::Point(8, 4);
            this->fcgPBNVEncLogoDisabled->Margin = System::Windows::Forms::Padding(4);
            this->fcgPBNVEncLogoDisabled->Name = L"fcgPBNVEncLogoDisabled";
            this->fcgPBNVEncLogoDisabled->Size = System::Drawing::Size(274, 94);
            this->fcgPBNVEncLogoDisabled->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->fcgPBNVEncLogoDisabled->TabIndex = 149;
            this->fcgPBNVEncLogoDisabled->TabStop = false;
            // 
            // fcgPNH264
            // 
            this->fcgPNH264->Controls->Add(this->fcgLBBluray);
            this->fcgPNH264->Controls->Add(this->fcgCBBluray);
            this->fcgPNH264->Controls->Add(this->fcgLBCodecProfile);
            this->fcgPNH264->Controls->Add(this->fcgLBCodecLevel);
            this->fcgPNH264->Controls->Add(this->fcgCXCodecProfile);
            this->fcgPNH264->Controls->Add(this->fcgCXCodecLevel);
            this->fcgPNH264->Controls->Add(this->fcgLBFullrangeH264);
            this->fcgPNH264->Controls->Add(this->fcgCBFullrangeH264);
            this->fcgPNH264->Controls->Add(this->fcgCXVideoFormatH264);
            this->fcgPNH264->Controls->Add(this->fcgLBVideoFormatH264);
            this->fcgPNH264->Controls->Add(this->fcggroupBoxColorH264);
            this->fcgPNH264->Location = System::Drawing::Point(426, 206);
            this->fcgPNH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNH264->Name = L"fcgPNH264";
            this->fcgPNH264->Size = System::Drawing::Size(330, 384);
            this->fcgPNH264->TabIndex = 152;
            // 
            // fcgLBBluray
            // 
            this->fcgLBBluray->AutoSize = true;
            this->fcgLBBluray->Location = System::Drawing::Point(20, 82);
            this->fcgLBBluray->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBluray->Name = L"fcgLBBluray";
            this->fcgLBBluray->Size = System::Drawing::Size(94, 18);
            this->fcgLBBluray->TabIndex = 156;
            this->fcgLBBluray->Text = L"Bluray用出力";
            // 
            // fcgCBBluray
            // 
            this->fcgCBBluray->AutoSize = true;
            this->fcgCBBluray->Location = System::Drawing::Point(160, 84);
            this->fcgCBBluray->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBBluray->Name = L"fcgCBBluray";
            this->fcgCBBluray->Size = System::Drawing::Size(18, 17);
            this->fcgCBBluray->TabIndex = 43;
            this->fcgCBBluray->Tag = L"chValue";
            this->fcgCBBluray->UseVisualStyleBackColor = true;
            // 
            // fcgLBCodecProfile
            // 
            this->fcgLBCodecProfile->AutoSize = true;
            this->fcgLBCodecProfile->Location = System::Drawing::Point(19, 10);
            this->fcgLBCodecProfile->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBCodecProfile->Name = L"fcgLBCodecProfile";
            this->fcgLBCodecProfile->Size = System::Drawing::Size(67, 18);
            this->fcgLBCodecProfile->TabIndex = 83;
            this->fcgLBCodecProfile->Text = L"プロファイル";
            // 
            // fcgLBCodecLevel
            // 
            this->fcgLBCodecLevel->AutoSize = true;
            this->fcgLBCodecLevel->Location = System::Drawing::Point(19, 48);
            this->fcgLBCodecLevel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBCodecLevel->Name = L"fcgLBCodecLevel";
            this->fcgLBCodecLevel->Size = System::Drawing::Size(41, 18);
            this->fcgLBCodecLevel->TabIndex = 84;
            this->fcgLBCodecLevel->Text = L"レベル";
            // 
            // fcgCXCodecProfile
            // 
            this->fcgCXCodecProfile->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXCodecProfile->FormattingEnabled = true;
            this->fcgCXCodecProfile->Location = System::Drawing::Point(158, 6);
            this->fcgCXCodecProfile->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXCodecProfile->Name = L"fcgCXCodecProfile";
            this->fcgCXCodecProfile->Size = System::Drawing::Size(150, 26);
            this->fcgCXCodecProfile->TabIndex = 41;
            this->fcgCXCodecProfile->Tag = L"chValue";
            // 
            // fcgCXCodecLevel
            // 
            this->fcgCXCodecLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXCodecLevel->FormattingEnabled = true;
            this->fcgCXCodecLevel->Location = System::Drawing::Point(158, 42);
            this->fcgCXCodecLevel->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXCodecLevel->Name = L"fcgCXCodecLevel";
            this->fcgCXCodecLevel->Size = System::Drawing::Size(150, 26);
            this->fcgCXCodecLevel->TabIndex = 42;
            this->fcgCXCodecLevel->Tag = L"chValue";
            // 
            // fcgLBFullrangeH264
            // 
            this->fcgLBFullrangeH264->AutoSize = true;
            this->fcgLBFullrangeH264->Location = System::Drawing::Point(24, 228);
            this->fcgLBFullrangeH264->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBFullrangeH264->Name = L"fcgLBFullrangeH264";
            this->fcgLBFullrangeH264->Size = System::Drawing::Size(69, 18);
            this->fcgLBFullrangeH264->TabIndex = 145;
            this->fcgLBFullrangeH264->Text = L"fullrange";
            // 
            // fcgCBFullrangeH264
            // 
            this->fcgCBFullrangeH264->AutoSize = true;
            this->fcgCBFullrangeH264->Location = System::Drawing::Point(158, 232);
            this->fcgCBFullrangeH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBFullrangeH264->Name = L"fcgCBFullrangeH264";
            this->fcgCBFullrangeH264->Size = System::Drawing::Size(18, 17);
            this->fcgCBFullrangeH264->TabIndex = 51;
            this->fcgCBFullrangeH264->Tag = L"chValue";
            this->fcgCBFullrangeH264->UseVisualStyleBackColor = true;
            // 
            // fcgCXVideoFormatH264
            // 
            this->fcgCXVideoFormatH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVideoFormatH264->FormattingEnabled = true;
            this->fcgCXVideoFormatH264->Location = System::Drawing::Point(158, 194);
            this->fcgCXVideoFormatH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXVideoFormatH264->Name = L"fcgCXVideoFormatH264";
            this->fcgCXVideoFormatH264->Size = System::Drawing::Size(150, 26);
            this->fcgCXVideoFormatH264->TabIndex = 50;
            this->fcgCXVideoFormatH264->Tag = L"chValue";
            // 
            // fcgLBVideoFormatH264
            // 
            this->fcgLBVideoFormatH264->AutoSize = true;
            this->fcgLBVideoFormatH264->Location = System::Drawing::Point(24, 196);
            this->fcgLBVideoFormatH264->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVideoFormatH264->Name = L"fcgLBVideoFormatH264";
            this->fcgLBVideoFormatH264->Size = System::Drawing::Size(90, 18);
            this->fcgLBVideoFormatH264->TabIndex = 144;
            this->fcgLBVideoFormatH264->Text = L"videoformat";
            // 
            // fcggroupBoxColorH264
            // 
            this->fcggroupBoxColorH264->Controls->Add(this->fcgCXTransferH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgCXColorPrimH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgCXColorMatrixH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgLBTransferH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgLBColorPrimH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgLBColorMatrixH264);
            this->fcggroupBoxColorH264->Location = System::Drawing::Point(19, 252);
            this->fcggroupBoxColorH264->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxColorH264->Name = L"fcggroupBoxColorH264";
            this->fcggroupBoxColorH264->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxColorH264->Size = System::Drawing::Size(301, 129);
            this->fcggroupBoxColorH264->TabIndex = 60;
            this->fcggroupBoxColorH264->TabStop = false;
            this->fcggroupBoxColorH264->Text = L"色設定";
            // 
            // fcgCXTransferH264
            // 
            this->fcgCXTransferH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXTransferH264->FormattingEnabled = true;
            this->fcgCXTransferH264->Location = System::Drawing::Point(139, 90);
            this->fcgCXTransferH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXTransferH264->Name = L"fcgCXTransferH264";
            this->fcgCXTransferH264->Size = System::Drawing::Size(150, 26);
            this->fcgCXTransferH264->TabIndex = 2;
            this->fcgCXTransferH264->Tag = L"chValue";
            // 
            // fcgCXColorPrimH264
            // 
            this->fcgCXColorPrimH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorPrimH264->FormattingEnabled = true;
            this->fcgCXColorPrimH264->Location = System::Drawing::Point(139, 55);
            this->fcgCXColorPrimH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXColorPrimH264->Name = L"fcgCXColorPrimH264";
            this->fcgCXColorPrimH264->Size = System::Drawing::Size(150, 26);
            this->fcgCXColorPrimH264->TabIndex = 1;
            this->fcgCXColorPrimH264->Tag = L"chValue";
            // 
            // fcgCXColorMatrixH264
            // 
            this->fcgCXColorMatrixH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorMatrixH264->FormattingEnabled = true;
            this->fcgCXColorMatrixH264->Location = System::Drawing::Point(139, 20);
            this->fcgCXColorMatrixH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXColorMatrixH264->Name = L"fcgCXColorMatrixH264";
            this->fcgCXColorMatrixH264->Size = System::Drawing::Size(150, 26);
            this->fcgCXColorMatrixH264->TabIndex = 0;
            this->fcgCXColorMatrixH264->Tag = L"chValue";
            // 
            // fcgLBTransferH264
            // 
            this->fcgLBTransferH264->AutoSize = true;
            this->fcgLBTransferH264->Location = System::Drawing::Point(22, 94);
            this->fcgLBTransferH264->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBTransferH264->Name = L"fcgLBTransferH264";
            this->fcgLBTransferH264->Size = System::Drawing::Size(62, 18);
            this->fcgLBTransferH264->TabIndex = 2;
            this->fcgLBTransferH264->Text = L"transfer";
            // 
            // fcgLBColorPrimH264
            // 
            this->fcgLBColorPrimH264->AutoSize = true;
            this->fcgLBColorPrimH264->Location = System::Drawing::Point(22, 59);
            this->fcgLBColorPrimH264->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBColorPrimH264->Name = L"fcgLBColorPrimH264";
            this->fcgLBColorPrimH264->Size = System::Drawing::Size(73, 18);
            this->fcgLBColorPrimH264->TabIndex = 1;
            this->fcgLBColorPrimH264->Text = L"colorprim";
            // 
            // fcgLBColorMatrixH264
            // 
            this->fcgLBColorMatrixH264->AutoSize = true;
            this->fcgLBColorMatrixH264->Location = System::Drawing::Point(22, 24);
            this->fcgLBColorMatrixH264->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBColorMatrixH264->Name = L"fcgLBColorMatrixH264";
            this->fcgLBColorMatrixH264->Size = System::Drawing::Size(85, 18);
            this->fcgLBColorMatrixH264->TabIndex = 0;
            this->fcgLBColorMatrixH264->Text = L"colormatrix";
            // 
            // fcgPNQP
            // 
            this->fcgPNQP->Controls->Add(this->fcgLBQPI);
            this->fcgPNQP->Controls->Add(this->fcgNUQPI);
            this->fcgPNQP->Controls->Add(this->fcgNUQPP);
            this->fcgPNQP->Controls->Add(this->fcgNUQPB);
            this->fcgPNQP->Controls->Add(this->fcgLBQPP);
            this->fcgPNQP->Controls->Add(this->fcgLBQPB);
            this->fcgPNQP->Location = System::Drawing::Point(10, 175);
            this->fcgPNQP->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNQP->Name = L"fcgPNQP";
            this->fcgPNQP->Size = System::Drawing::Size(361, 99);
            this->fcgPNQP->TabIndex = 113;
            // 
            // fcgLBQPI
            // 
            this->fcgLBQPI->AutoSize = true;
            this->fcgLBQPI->Location = System::Drawing::Point(12, 5);
            this->fcgLBQPI->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBQPI->Name = L"fcgLBQPI";
            this->fcgLBQPI->Size = System::Drawing::Size(83, 18);
            this->fcgLBQPI->TabIndex = 75;
            this->fcgLBQPI->Text = L"QP I frame";
            // 
            // fcgNUQPI
            // 
            this->fcgNUQPI->Location = System::Drawing::Point(155, 2);
            this->fcgNUQPI->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPI->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPI->Name = L"fcgNUQPI";
            this->fcgNUQPI->Size = System::Drawing::Size(96, 25);
            this->fcgNUQPI->TabIndex = 5;
            this->fcgNUQPI->Tag = L"chValue";
            this->fcgNUQPI->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUQPP
            // 
            this->fcgNUQPP->Location = System::Drawing::Point(155, 36);
            this->fcgNUQPP->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPP->Name = L"fcgNUQPP";
            this->fcgNUQPP->Size = System::Drawing::Size(96, 25);
            this->fcgNUQPP->TabIndex = 6;
            this->fcgNUQPP->Tag = L"chValue";
            this->fcgNUQPP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUQPB
            // 
            this->fcgNUQPB->Location = System::Drawing::Point(155, 69);
            this->fcgNUQPB->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPB->Name = L"fcgNUQPB";
            this->fcgNUQPB->Size = System::Drawing::Size(96, 25);
            this->fcgNUQPB->TabIndex = 7;
            this->fcgNUQPB->Tag = L"chValue";
            this->fcgNUQPB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBQPP
            // 
            this->fcgLBQPP->AutoSize = true;
            this->fcgLBQPP->Location = System::Drawing::Point(12, 39);
            this->fcgLBQPP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBQPP->Name = L"fcgLBQPP";
            this->fcgLBQPP->Size = System::Drawing::Size(85, 18);
            this->fcgLBQPP->TabIndex = 76;
            this->fcgLBQPP->Text = L"QP P frame";
            // 
            // fcgLBQPB
            // 
            this->fcgLBQPB->AutoSize = true;
            this->fcgLBQPB->Location = System::Drawing::Point(8, 71);
            this->fcgLBQPB->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBQPB->Name = L"fcgLBQPB";
            this->fcgLBQPB->Size = System::Drawing::Size(86, 18);
            this->fcgLBQPB->TabIndex = 77;
            this->fcgLBQPB->Text = L"QP B frame";
            // 
            // tabPageVideoDetail
            // 
            this->tabPageVideoDetail->Controls->Add(this->fcgCBAuoTcfileout);
            this->tabPageVideoDetail->Controls->Add(this->fcgLBTempDir);
            this->tabPageVideoDetail->Controls->Add(this->fcgBTCustomTempDir);
            this->tabPageVideoDetail->Controls->Add(this->fcgTXCustomTempDir);
            this->tabPageVideoDetail->Controls->Add(this->fcgCXTempDir);
            this->tabPageVideoDetail->Controls->Add(this->fcgLBCudaSchdule);
            this->tabPageVideoDetail->Controls->Add(this->fcgCXCudaSchdule);
            this->tabPageVideoDetail->Controls->Add(this->fcgCBPerfMonitor);
            this->tabPageVideoDetail->Controls->Add(this->fcgGroupBoxQulaityStg);
            this->tabPageVideoDetail->Controls->Add(this->groupBoxQPDetail);
            this->tabPageVideoDetail->Controls->Add(this->fcgLBDevice);
            this->tabPageVideoDetail->Controls->Add(this->fcgCXDevice);
            this->tabPageVideoDetail->Controls->Add(this->fcgLBSlices);
            this->tabPageVideoDetail->Controls->Add(this->fcgNUSlices);
            this->tabPageVideoDetail->Controls->Add(this->fcgPNH264Detail);
            this->tabPageVideoDetail->Controls->Add(this->fcgPNHEVCDetail);
            this->tabPageVideoDetail->Location = System::Drawing::Point(4, 28);
            this->tabPageVideoDetail->Margin = System::Windows::Forms::Padding(4);
            this->tabPageVideoDetail->Name = L"tabPageVideoDetail";
            this->tabPageVideoDetail->Size = System::Drawing::Size(762, 604);
            this->tabPageVideoDetail->TabIndex = 3;
            this->tabPageVideoDetail->Text = L"詳細設定";
            this->tabPageVideoDetail->UseVisualStyleBackColor = true;
            // 
            // fcgCBAuoTcfileout
            // 
            this->fcgCBAuoTcfileout->AutoSize = true;
            this->fcgCBAuoTcfileout->Location = System::Drawing::Point(30, 534);
            this->fcgCBAuoTcfileout->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBAuoTcfileout->Name = L"fcgCBAuoTcfileout";
            this->fcgCBAuoTcfileout->Size = System::Drawing::Size(127, 23);
            this->fcgCBAuoTcfileout->TabIndex = 167;
            this->fcgCBAuoTcfileout->Tag = L"chValue";
            this->fcgCBAuoTcfileout->Text = L"タイムコード出力";
            this->fcgCBAuoTcfileout->UseVisualStyleBackColor = true;
            // 
            // fcgLBTempDir
            // 
            this->fcgLBTempDir->AutoSize = true;
            this->fcgLBTempDir->Location = System::Drawing::Point(24, 455);
            this->fcgLBTempDir->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBTempDir->Name = L"fcgLBTempDir";
            this->fcgLBTempDir->Size = System::Drawing::Size(82, 19);
            this->fcgLBTempDir->TabIndex = 165;
            this->fcgLBTempDir->Text = L"一時フォルダ";
            // 
            // fcgBTCustomTempDir
            // 
            this->fcgBTCustomTempDir->Location = System::Drawing::Point(352, 485);
            this->fcgBTCustomTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTCustomTempDir->Name = L"fcgBTCustomTempDir";
            this->fcgBTCustomTempDir->Size = System::Drawing::Size(36, 29);
            this->fcgBTCustomTempDir->TabIndex = 164;
            this->fcgBTCustomTempDir->Text = L"...";
            this->fcgBTCustomTempDir->UseVisualStyleBackColor = true;
            this->fcgBTCustomTempDir->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTCustomTempDir_Click);
            // 
            // fcgTXCustomTempDir
            // 
            this->fcgTXCustomTempDir->Location = System::Drawing::Point(121, 486);
            this->fcgTXCustomTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXCustomTempDir->Name = L"fcgTXCustomTempDir";
            this->fcgTXCustomTempDir->Size = System::Drawing::Size(226, 27);
            this->fcgTXCustomTempDir->TabIndex = 163;
            this->fcgTXCustomTempDir->Tag = L"";
            this->fcgTXCustomTempDir->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXCustomTempDir_TextChanged);
            // 
            // fcgCXTempDir
            // 
            this->fcgCXTempDir->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXTempDir->FormattingEnabled = true;
            this->fcgCXTempDir->Location = System::Drawing::Point(106, 451);
            this->fcgCXTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXTempDir->Name = L"fcgCXTempDir";
            this->fcgCXTempDir->Size = System::Drawing::Size(260, 27);
            this->fcgCXTempDir->TabIndex = 162;
            this->fcgCXTempDir->Tag = L"chValue";
            // 
            // fcgLBCudaSchdule
            // 
            this->fcgLBCudaSchdule->AutoSize = true;
            this->fcgLBCudaSchdule->Location = System::Drawing::Point(25, 68);
            this->fcgLBCudaSchdule->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBCudaSchdule->Name = L"fcgLBCudaSchdule";
            this->fcgLBCudaSchdule->Size = System::Drawing::Size(120, 19);
            this->fcgLBCudaSchdule->TabIndex = 161;
            this->fcgLBCudaSchdule->Text = L"CUDAスケジュール";
            // 
            // fcgCXCudaSchdule
            // 
            this->fcgCXCudaSchdule->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXCudaSchdule->FormattingEnabled = true;
            this->fcgCXCudaSchdule->Location = System::Drawing::Point(161, 64);
            this->fcgCXCudaSchdule->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXCudaSchdule->Name = L"fcgCXCudaSchdule";
            this->fcgCXCudaSchdule->Size = System::Drawing::Size(223, 27);
            this->fcgCXCudaSchdule->TabIndex = 160;
            this->fcgCXCudaSchdule->Tag = L"chValue";
            // 
            // fcgCBPerfMonitor
            // 
            this->fcgCBPerfMonitor->AutoSize = true;
            this->fcgCBPerfMonitor->Location = System::Drawing::Point(30, 566);
            this->fcgCBPerfMonitor->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBPerfMonitor->Name = L"fcgCBPerfMonitor";
            this->fcgCBPerfMonitor->Size = System::Drawing::Size(162, 23);
            this->fcgCBPerfMonitor->TabIndex = 159;
            this->fcgCBPerfMonitor->Tag = L"chValue";
            this->fcgCBPerfMonitor->Text = L"パフォーマンスログ出力";
            this->fcgCBPerfMonitor->UseVisualStyleBackColor = true;
            // 
            // fcgGroupBoxQulaityStg
            // 
            this->fcgGroupBoxQulaityStg->Controls->Add(this->fcgBTQualityStg);
            this->fcgGroupBoxQulaityStg->Controls->Add(this->fcgCXQualityPreset);
            this->fcgGroupBoxQulaityStg->Location = System::Drawing::Point(465, 505);
            this->fcgGroupBoxQulaityStg->Margin = System::Windows::Forms::Padding(4);
            this->fcgGroupBoxQulaityStg->Name = L"fcgGroupBoxQulaityStg";
            this->fcgGroupBoxQulaityStg->Padding = System::Windows::Forms::Padding(4);
            this->fcgGroupBoxQulaityStg->Size = System::Drawing::Size(274, 88);
            this->fcgGroupBoxQulaityStg->TabIndex = 80;
            this->fcgGroupBoxQulaityStg->TabStop = false;
            this->fcgGroupBoxQulaityStg->Text = L"品質設定";
            this->fcgGroupBoxQulaityStg->Visible = false;
            // 
            // fcgBTQualityStg
            // 
            this->fcgBTQualityStg->Location = System::Drawing::Point(132, 52);
            this->fcgBTQualityStg->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTQualityStg->Name = L"fcgBTQualityStg";
            this->fcgBTQualityStg->Size = System::Drawing::Size(121, 28);
            this->fcgBTQualityStg->TabIndex = 1;
            this->fcgBTQualityStg->Text = L"ロードして反映";
            this->fcgBTQualityStg->UseVisualStyleBackColor = true;
            // 
            // fcgCXQualityPreset
            // 
            this->fcgCXQualityPreset->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXQualityPreset->FormattingEnabled = true;
            this->fcgCXQualityPreset->Location = System::Drawing::Point(32, 21);
            this->fcgCXQualityPreset->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXQualityPreset->Name = L"fcgCXQualityPreset";
            this->fcgCXQualityPreset->Size = System::Drawing::Size(216, 27);
            this->fcgCXQualityPreset->TabIndex = 0;
            this->fcgCXQualityPreset->Tag = L"chValue";
            // 
            // groupBoxQPDetail
            // 
            this->groupBoxQPDetail->Controls->Add(this->fcgLBQPDetailB);
            this->groupBoxQPDetail->Controls->Add(this->fcgLBQPDetailP);
            this->groupBoxQPDetail->Controls->Add(this->fcgLBQPDetailI);
            this->groupBoxQPDetail->Controls->Add(this->fcgCBQPInit);
            this->groupBoxQPDetail->Controls->Add(this->label16);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPInitB);
            this->groupBoxQPDetail->Controls->Add(this->label18);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPInitP);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPInitI);
            this->groupBoxQPDetail->Controls->Add(this->fcgCBQPMin);
            this->groupBoxQPDetail->Controls->Add(this->label11);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPMinB);
            this->groupBoxQPDetail->Controls->Add(this->label13);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPMinP);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPMinI);
            this->groupBoxQPDetail->Controls->Add(this->fcgCBQPMax);
            this->groupBoxQPDetail->Controls->Add(this->label8);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPMaxB);
            this->groupBoxQPDetail->Controls->Add(this->label7);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPMaxP);
            this->groupBoxQPDetail->Controls->Add(this->fcgNUQPMaxI);
            this->groupBoxQPDetail->Location = System::Drawing::Point(18, 149);
            this->groupBoxQPDetail->Margin = System::Windows::Forms::Padding(4);
            this->groupBoxQPDetail->Name = L"groupBoxQPDetail";
            this->groupBoxQPDetail->Padding = System::Windows::Forms::Padding(4);
            this->groupBoxQPDetail->Size = System::Drawing::Size(356, 172);
            this->groupBoxQPDetail->TabIndex = 10;
            this->groupBoxQPDetail->TabStop = false;
            this->groupBoxQPDetail->Text = L"QP詳細設定";
            // 
            // fcgLBQPDetailB
            // 
            this->fcgLBQPDetailB->AutoSize = true;
            this->fcgLBQPDetailB->Location = System::Drawing::Point(268, 24);
            this->fcgLBQPDetailB->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBQPDetailB->Name = L"fcgLBQPDetailB";
            this->fcgLBQPDetailB->Size = System::Drawing::Size(64, 19);
            this->fcgLBQPDetailB->TabIndex = 162;
            this->fcgLBQPDetailB->Text = L"Bフレーム";
            // 
            // fcgLBQPDetailP
            // 
            this->fcgLBQPDetailP->AutoSize = true;
            this->fcgLBQPDetailP->Location = System::Drawing::Point(185, 24);
            this->fcgLBQPDetailP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBQPDetailP->Name = L"fcgLBQPDetailP";
            this->fcgLBQPDetailP->Size = System::Drawing::Size(63, 19);
            this->fcgLBQPDetailP->TabIndex = 161;
            this->fcgLBQPDetailP->Text = L"Pフレーム";
            // 
            // fcgLBQPDetailI
            // 
            this->fcgLBQPDetailI->AutoSize = true;
            this->fcgLBQPDetailI->Location = System::Drawing::Point(100, 24);
            this->fcgLBQPDetailI->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBQPDetailI->Name = L"fcgLBQPDetailI";
            this->fcgLBQPDetailI->Size = System::Drawing::Size(60, 19);
            this->fcgLBQPDetailI->TabIndex = 160;
            this->fcgLBQPDetailI->Text = L"Iフレーム";
            // 
            // fcgCBQPInit
            // 
            this->fcgCBQPInit->AutoSize = true;
            this->fcgCBQPInit->Location = System::Drawing::Point(12, 125);
            this->fcgCBQPInit->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBQPInit->Name = L"fcgCBQPInit";
            this->fcgCBQPInit->Size = System::Drawing::Size(76, 23);
            this->fcgCBQPInit->TabIndex = 8;
            this->fcgCBQPInit->Tag = L"chValue";
            this->fcgCBQPInit->Text = L"初期値";
            this->fcgCBQPInit->UseVisualStyleBackColor = true;
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(249, 125);
            this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(15, 19);
            this->label16->TabIndex = 32;
            this->label16->Text = L":";
            // 
            // fcgNUQPInitB
            // 
            this->fcgNUQPInitB->Location = System::Drawing::Point(269, 122);
            this->fcgNUQPInitB->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPInitB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUQPInitB->Name = L"fcgNUQPInitB";
            this->fcgNUQPInitB->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPInitB->TabIndex = 11;
            this->fcgNUQPInitB->Tag = L"51";
            this->fcgNUQPInitB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Location = System::Drawing::Point(166, 125);
            this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(15, 19);
            this->label18->TabIndex = 30;
            this->label18->Text = L":";
            // 
            // fcgNUQPInitP
            // 
            this->fcgNUQPInitP->Location = System::Drawing::Point(186, 122);
            this->fcgNUQPInitP->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPInitP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPInitP->Name = L"fcgNUQPInitP";
            this->fcgNUQPInitP->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPInitP->TabIndex = 10;
            this->fcgNUQPInitP->Tag = L"chValue";
            this->fcgNUQPInitP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUQPInitI
            // 
            this->fcgNUQPInitI->Location = System::Drawing::Point(104, 122);
            this->fcgNUQPInitI->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPInitI->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPInitI->Name = L"fcgNUQPInitI";
            this->fcgNUQPInitI->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPInitI->TabIndex = 9;
            this->fcgNUQPInitI->Tag = L"chValue";
            this->fcgNUQPInitI->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgCBQPMin
            // 
            this->fcgCBQPMin->AutoSize = true;
            this->fcgCBQPMin->Location = System::Drawing::Point(12, 54);
            this->fcgCBQPMin->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBQPMin->Name = L"fcgCBQPMin";
            this->fcgCBQPMin->Size = System::Drawing::Size(61, 23);
            this->fcgCBQPMin->TabIndex = 0;
            this->fcgCBQPMin->Tag = L"chValue";
            this->fcgCBQPMin->Text = L"下限";
            this->fcgCBQPMin->UseVisualStyleBackColor = true;
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(249, 54);
            this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(15, 19);
            this->label11->TabIndex = 26;
            this->label11->Text = L":";
            // 
            // fcgNUQPMinB
            // 
            this->fcgNUQPMinB->Location = System::Drawing::Point(269, 51);
            this->fcgNUQPMinB->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPMinB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPMinB->Name = L"fcgNUQPMinB";
            this->fcgNUQPMinB->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPMinB->TabIndex = 3;
            this->fcgNUQPMinB->Tag = L"chValue";
            this->fcgNUQPMinB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(166, 54);
            this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(15, 19);
            this->label13->TabIndex = 24;
            this->label13->Text = L":";
            // 
            // fcgNUQPMinP
            // 
            this->fcgNUQPMinP->Location = System::Drawing::Point(186, 51);
            this->fcgNUQPMinP->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPMinP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPMinP->Name = L"fcgNUQPMinP";
            this->fcgNUQPMinP->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPMinP->TabIndex = 2;
            this->fcgNUQPMinP->Tag = L"chValue";
            this->fcgNUQPMinP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUQPMinI
            // 
            this->fcgNUQPMinI->Location = System::Drawing::Point(104, 51);
            this->fcgNUQPMinI->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPMinI->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPMinI->Name = L"fcgNUQPMinI";
            this->fcgNUQPMinI->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPMinI->TabIndex = 1;
            this->fcgNUQPMinI->Tag = L"chValue";
            this->fcgNUQPMinI->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgCBQPMax
            // 
            this->fcgCBQPMax->AutoSize = true;
            this->fcgCBQPMax->Location = System::Drawing::Point(12, 89);
            this->fcgCBQPMax->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBQPMax->Name = L"fcgCBQPMax";
            this->fcgCBQPMax->Size = System::Drawing::Size(61, 23);
            this->fcgCBQPMax->TabIndex = 4;
            this->fcgCBQPMax->Tag = L"chValue";
            this->fcgCBQPMax->Text = L"上限";
            this->fcgCBQPMax->UseVisualStyleBackColor = true;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(249, 89);
            this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(15, 19);
            this->label8->TabIndex = 5;
            this->label8->Text = L":";
            // 
            // fcgNUQPMaxB
            // 
            this->fcgNUQPMaxB->Location = System::Drawing::Point(269, 86);
            this->fcgNUQPMaxB->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPMaxB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPMaxB->Name = L"fcgNUQPMaxB";
            this->fcgNUQPMaxB->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPMaxB->TabIndex = 7;
            this->fcgNUQPMaxB->Tag = L"chValue";
            this->fcgNUQPMaxB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(166, 89);
            this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(15, 19);
            this->label7->TabIndex = 3;
            this->label7->Text = L":";
            // 
            // fcgNUQPMaxP
            // 
            this->fcgNUQPMaxP->Location = System::Drawing::Point(186, 86);
            this->fcgNUQPMaxP->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPMaxP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPMaxP->Name = L"fcgNUQPMaxP";
            this->fcgNUQPMaxP->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPMaxP->TabIndex = 6;
            this->fcgNUQPMaxP->Tag = L"chValue";
            this->fcgNUQPMaxP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUQPMaxI
            // 
            this->fcgNUQPMaxI->Location = System::Drawing::Point(104, 86);
            this->fcgNUQPMaxI->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUQPMaxI->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPMaxI->Name = L"fcgNUQPMaxI";
            this->fcgNUQPMaxI->Size = System::Drawing::Size(60, 27);
            this->fcgNUQPMaxI->TabIndex = 5;
            this->fcgNUQPMaxI->Tag = L"chValue";
            this->fcgNUQPMaxI->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBDevice
            // 
            this->fcgLBDevice->AutoSize = true;
            this->fcgLBDevice->Location = System::Drawing::Point(25, 29);
            this->fcgLBDevice->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBDevice->Name = L"fcgLBDevice";
            this->fcgLBDevice->Size = System::Drawing::Size(56, 19);
            this->fcgLBDevice->TabIndex = 158;
            this->fcgLBDevice->Text = L"デバイス";
            // 
            // fcgCXDevice
            // 
            this->fcgCXDevice->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXDevice->FormattingEnabled = true;
            this->fcgCXDevice->Location = System::Drawing::Point(161, 25);
            this->fcgCXDevice->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXDevice->Name = L"fcgCXDevice";
            this->fcgCXDevice->Size = System::Drawing::Size(223, 27);
            this->fcgCXDevice->TabIndex = 0;
            this->fcgCXDevice->Tag = L"chValue";
            // 
            // fcgLBSlices
            // 
            this->fcgLBSlices->AutoSize = true;
            this->fcgLBSlices->Location = System::Drawing::Point(26, 106);
            this->fcgLBSlices->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBSlices->Name = L"fcgLBSlices";
            this->fcgLBSlices->Size = System::Drawing::Size(67, 19);
            this->fcgLBSlices->TabIndex = 155;
            this->fcgLBSlices->Text = L"スライス数";
            // 
            // fcgNUSlices
            // 
            this->fcgNUSlices->Location = System::Drawing::Point(162, 104);
            this->fcgNUSlices->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUSlices->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUSlices->Name = L"fcgNUSlices";
            this->fcgNUSlices->Size = System::Drawing::Size(88, 27);
            this->fcgNUSlices->TabIndex = 1;
            this->fcgNUSlices->Tag = L"chValue";
            this->fcgNUSlices->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUSlices->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgPNH264Detail
            // 
            this->fcgPNH264Detail->Controls->Add(this->fcgLBDeblock);
            this->fcgPNH264Detail->Controls->Add(this->fcgCXAdaptiveTransform);
            this->fcgPNH264Detail->Controls->Add(this->fcgLBAdaptiveTransform);
            this->fcgPNH264Detail->Controls->Add(this->fcgCXBDirectMode);
            this->fcgPNH264Detail->Controls->Add(this->fcgLBBDirectMode);
            this->fcgPNH264Detail->Controls->Add(this->fcgLBMVPrecision);
            this->fcgPNH264Detail->Controls->Add(this->fcgCXMVPrecision);
            this->fcgPNH264Detail->Controls->Add(this->fcgCBDeblock);
            this->fcgPNH264Detail->Controls->Add(this->fcgCBCABAC);
            this->fcgPNH264Detail->Controls->Add(this->fcgLBCABAC);
            this->fcgPNH264Detail->Location = System::Drawing::Point(409, 16);
            this->fcgPNH264Detail->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNH264Detail->Name = L"fcgPNH264Detail";
            this->fcgPNH264Detail->Size = System::Drawing::Size(330, 212);
            this->fcgPNH264Detail->TabIndex = 50;
            // 
            // fcgLBDeblock
            // 
            this->fcgLBDeblock->AutoSize = true;
            this->fcgLBDeblock->Location = System::Drawing::Point(19, 49);
            this->fcgLBDeblock->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBDeblock->Name = L"fcgLBDeblock";
            this->fcgLBDeblock->Size = System::Drawing::Size(102, 19);
            this->fcgLBDeblock->TabIndex = 154;
            this->fcgLBDeblock->Text = L"デブロックフィルタ";
            // 
            // fcgCXAdaptiveTransform
            // 
            this->fcgCXAdaptiveTransform->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAdaptiveTransform->FormattingEnabled = true;
            this->fcgCXAdaptiveTransform->Location = System::Drawing::Point(156, 81);
            this->fcgCXAdaptiveTransform->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAdaptiveTransform->Name = L"fcgCXAdaptiveTransform";
            this->fcgCXAdaptiveTransform->Size = System::Drawing::Size(152, 27);
            this->fcgCXAdaptiveTransform->TabIndex = 53;
            this->fcgCXAdaptiveTransform->Tag = L"chValue";
            // 
            // fcgLBAdaptiveTransform
            // 
            this->fcgLBAdaptiveTransform->AutoSize = true;
            this->fcgLBAdaptiveTransform->Location = System::Drawing::Point(19, 85);
            this->fcgLBAdaptiveTransform->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAdaptiveTransform->Name = L"fcgLBAdaptiveTransform";
            this->fcgLBAdaptiveTransform->Size = System::Drawing::Size(136, 19);
            this->fcgLBAdaptiveTransform->TabIndex = 148;
            this->fcgLBAdaptiveTransform->Text = L"Adapt. Transform";
            // 
            // fcgCXBDirectMode
            // 
            this->fcgCXBDirectMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXBDirectMode->FormattingEnabled = true;
            this->fcgCXBDirectMode->Location = System::Drawing::Point(156, 160);
            this->fcgCXBDirectMode->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXBDirectMode->Name = L"fcgCXBDirectMode";
            this->fcgCXBDirectMode->Size = System::Drawing::Size(152, 27);
            this->fcgCXBDirectMode->TabIndex = 55;
            this->fcgCXBDirectMode->Tag = L"chValue";
            // 
            // fcgLBBDirectMode
            // 
            this->fcgLBBDirectMode->AutoSize = true;
            this->fcgLBBDirectMode->Location = System::Drawing::Point(21, 164);
            this->fcgLBBDirectMode->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBDirectMode->Name = L"fcgLBBDirectMode";
            this->fcgLBBDirectMode->Size = System::Drawing::Size(95, 19);
            this->fcgLBBDirectMode->TabIndex = 137;
            this->fcgLBBDirectMode->Text = L"動き予測方式";
            // 
            // fcgLBMVPrecision
            // 
            this->fcgLBMVPrecision->AutoSize = true;
            this->fcgLBMVPrecision->Location = System::Drawing::Point(19, 125);
            this->fcgLBMVPrecision->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBMVPrecision->Name = L"fcgLBMVPrecision";
            this->fcgLBMVPrecision->Size = System::Drawing::Size(95, 19);
            this->fcgLBMVPrecision->TabIndex = 135;
            this->fcgLBMVPrecision->Text = L"動き探索精度";
            // 
            // fcgCXMVPrecision
            // 
            this->fcgCXMVPrecision->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMVPrecision->FormattingEnabled = true;
            this->fcgCXMVPrecision->Location = System::Drawing::Point(156, 120);
            this->fcgCXMVPrecision->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXMVPrecision->Name = L"fcgCXMVPrecision";
            this->fcgCXMVPrecision->Size = System::Drawing::Size(152, 27);
            this->fcgCXMVPrecision->TabIndex = 54;
            this->fcgCXMVPrecision->Tag = L"chValue";
            // 
            // fcgCBDeblock
            // 
            this->fcgCBDeblock->AutoSize = true;
            this->fcgCBDeblock->Location = System::Drawing::Point(159, 50);
            this->fcgCBDeblock->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBDeblock->Name = L"fcgCBDeblock";
            this->fcgCBDeblock->Size = System::Drawing::Size(18, 17);
            this->fcgCBDeblock->TabIndex = 52;
            this->fcgCBDeblock->Tag = L"chValue";
            this->fcgCBDeblock->UseVisualStyleBackColor = true;
            // 
            // fcgCBCABAC
            // 
            this->fcgCBCABAC->AutoSize = true;
            this->fcgCBCABAC->Location = System::Drawing::Point(159, 16);
            this->fcgCBCABAC->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBCABAC->Name = L"fcgCBCABAC";
            this->fcgCBCABAC->Size = System::Drawing::Size(18, 17);
            this->fcgCBCABAC->TabIndex = 51;
            this->fcgCBCABAC->Tag = L"chValue";
            this->fcgCBCABAC->UseVisualStyleBackColor = true;
            // 
            // fcgLBCABAC
            // 
            this->fcgLBCABAC->AutoSize = true;
            this->fcgLBCABAC->Location = System::Drawing::Point(19, 15);
            this->fcgLBCABAC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBCABAC->Name = L"fcgLBCABAC";
            this->fcgLBCABAC->Size = System::Drawing::Size(59, 19);
            this->fcgLBCABAC->TabIndex = 131;
            this->fcgLBCABAC->Text = L"CABAC";
            // 
            // fcgPNHEVCDetail
            // 
            this->fcgPNHEVCDetail->Controls->Add(this->fcgLBHEVCMinCUSize);
            this->fcgPNHEVCDetail->Controls->Add(this->fcgCXHEVCMinCUSize);
            this->fcgPNHEVCDetail->Controls->Add(this->fcgLBHEVCMaxCUSize);
            this->fcgPNHEVCDetail->Controls->Add(this->fcgCXHEVCMaxCUSize);
            this->fcgPNHEVCDetail->Location = System::Drawing::Point(409, 16);
            this->fcgPNHEVCDetail->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNHEVCDetail->Name = L"fcgPNHEVCDetail";
            this->fcgPNHEVCDetail->Size = System::Drawing::Size(330, 212);
            this->fcgPNHEVCDetail->TabIndex = 40;
            // 
            // fcgLBHEVCMinCUSize
            // 
            this->fcgLBHEVCMinCUSize->AutoSize = true;
            this->fcgLBHEVCMinCUSize->Location = System::Drawing::Point(25, 52);
            this->fcgLBHEVCMinCUSize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBHEVCMinCUSize->Name = L"fcgLBHEVCMinCUSize";
            this->fcgLBHEVCMinCUSize->Size = System::Drawing::Size(95, 19);
            this->fcgLBHEVCMinCUSize->TabIndex = 149;
            this->fcgLBHEVCMinCUSize->Text = L"最小CUサイズ";
            // 
            // fcgCXHEVCMinCUSize
            // 
            this->fcgCXHEVCMinCUSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCMinCUSize->FormattingEnabled = true;
            this->fcgCXHEVCMinCUSize->Location = System::Drawing::Point(161, 49);
            this->fcgCXHEVCMinCUSize->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXHEVCMinCUSize->Name = L"fcgCXHEVCMinCUSize";
            this->fcgCXHEVCMinCUSize->Size = System::Drawing::Size(150, 27);
            this->fcgCXHEVCMinCUSize->TabIndex = 42;
            this->fcgCXHEVCMinCUSize->Tag = L"chValue";
            // 
            // fcgLBHEVCMaxCUSize
            // 
            this->fcgLBHEVCMaxCUSize->AutoSize = true;
            this->fcgLBHEVCMaxCUSize->Location = System::Drawing::Point(25, 15);
            this->fcgLBHEVCMaxCUSize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBHEVCMaxCUSize->Name = L"fcgLBHEVCMaxCUSize";
            this->fcgLBHEVCMaxCUSize->Size = System::Drawing::Size(95, 19);
            this->fcgLBHEVCMaxCUSize->TabIndex = 147;
            this->fcgLBHEVCMaxCUSize->Text = L"最大CUサイズ";
            // 
            // fcgCXHEVCMaxCUSize
            // 
            this->fcgCXHEVCMaxCUSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCMaxCUSize->FormattingEnabled = true;
            this->fcgCXHEVCMaxCUSize->Location = System::Drawing::Point(161, 11);
            this->fcgCXHEVCMaxCUSize->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXHEVCMaxCUSize->Name = L"fcgCXHEVCMaxCUSize";
            this->fcgCXHEVCMaxCUSize->Size = System::Drawing::Size(150, 27);
            this->fcgCXHEVCMaxCUSize->TabIndex = 41;
            this->fcgCXHEVCMaxCUSize->Tag = L"chValue";
            // 
            // tabPageExOpt
            // 
            this->tabPageExOpt->Controls->Add(this->fcgCBVppTweakEnable);
            this->tabPageExOpt->Controls->Add(this->fcggroupBoxVppTweak);
            this->tabPageExOpt->Controls->Add(this->fcgCBVppPerfMonitor);
            this->tabPageExOpt->Controls->Add(this->fcggroupBoxVppDetailEnahance);
            this->tabPageExOpt->Controls->Add(this->fcgCBVppAfsEnable);
            this->tabPageExOpt->Controls->Add(this->fcggroupBoxVppAfs);
            this->tabPageExOpt->Controls->Add(this->fcgCBVppDebandEnable);
            this->tabPageExOpt->Controls->Add(this->fcggroupBoxVppDeband);
            this->tabPageExOpt->Controls->Add(this->fcggroupBoxVppDenoise);
            this->tabPageExOpt->Controls->Add(this->fcgCBVppResize);
            this->tabPageExOpt->Controls->Add(this->fcggroupBoxResize);
            this->tabPageExOpt->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->tabPageExOpt->Location = System::Drawing::Point(4, 28);
            this->tabPageExOpt->Margin = System::Windows::Forms::Padding(4);
            this->tabPageExOpt->Name = L"tabPageExOpt";
            this->tabPageExOpt->Size = System::Drawing::Size(762, 604);
            this->tabPageExOpt->TabIndex = 1;
            this->tabPageExOpt->Text = L"フィルタ";
            this->tabPageExOpt->UseVisualStyleBackColor = true;
            // 
            // fcgCBVppTweakEnable
            // 
            this->fcgCBVppTweakEnable->AutoSize = true;
            this->fcgCBVppTweakEnable->Location = System::Drawing::Point(462, 412);
            this->fcgCBVppTweakEnable->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppTweakEnable->Name = L"fcgCBVppTweakEnable";
            this->fcgCBVppTweakEnable->Size = System::Drawing::Size(86, 22);
            this->fcgCBVppTweakEnable->TabIndex = 169;
            this->fcgCBVppTweakEnable->Tag = L"chValue";
            this->fcgCBVppTweakEnable->Text = L"色調補正";
            this->fcgCBVppTweakEnable->UseVisualStyleBackColor = true;
            this->fcgCBVppTweakEnable->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcggroupBoxVppTweak
            // 
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgTBVppTweakHue);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgLBVppTweakHue);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgTBVppTweakSaturation);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgLBVppTweakSaturation);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgTBVppTweakGamma);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgLBVppTweakGamma);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgTBVppTweakContrast);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgLBVppTweakContrast);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgTBVppTweakBrightness);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgNUVppTweakGamma);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgNUVppTweakSaturation);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgNUVppTweakHue);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgLBVppTweakBrightness);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgNUVppTweakContrast);
            this->fcggroupBoxVppTweak->Controls->Add(this->fcgNUVppTweakBrightness);
            this->fcggroupBoxVppTweak->Location = System::Drawing::Point(448, 414);
            this->fcggroupBoxVppTweak->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppTweak->Name = L"fcggroupBoxVppTweak";
            this->fcggroupBoxVppTweak->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppTweak->Size = System::Drawing::Size(309, 181);
            this->fcggroupBoxVppTweak->TabIndex = 168;
            this->fcggroupBoxVppTweak->TabStop = false;
            // 
            // fcgTBVppTweakHue
            // 
            this->fcgTBVppTweakHue->AutoSize = false;
            this->fcgTBVppTweakHue->LargeChange = 10;
            this->fcgTBVppTweakHue->Location = System::Drawing::Point(75, 149);
            this->fcgTBVppTweakHue->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppTweakHue->Maximum = 180;
            this->fcgTBVppTweakHue->Minimum = -180;
            this->fcgTBVppTweakHue->Name = L"fcgTBVppTweakHue";
            this->fcgTBVppTweakHue->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppTweakHue->TabIndex = 113;
            this->fcgTBVppTweakHue->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppTweakHue->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppTweakScroll);
            // 
            // fcgLBVppTweakHue
            // 
            this->fcgLBVppTweakHue->AutoSize = true;
            this->fcgLBVppTweakHue->Location = System::Drawing::Point(11, 149);
            this->fcgLBVppTweakHue->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppTweakHue->Name = L"fcgLBVppTweakHue";
            this->fcgLBVppTweakHue->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppTweakHue->TabIndex = 112;
            this->fcgLBVppTweakHue->Text = L"色相";
            // 
            // fcgTBVppTweakSaturation
            // 
            this->fcgTBVppTweakSaturation->AutoSize = false;
            this->fcgTBVppTweakSaturation->Location = System::Drawing::Point(75, 118);
            this->fcgTBVppTweakSaturation->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppTweakSaturation->Maximum = 300;
            this->fcgTBVppTweakSaturation->Name = L"fcgTBVppTweakSaturation";
            this->fcgTBVppTweakSaturation->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppTweakSaturation->TabIndex = 111;
            this->fcgTBVppTweakSaturation->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppTweakSaturation->Value = 100;
            this->fcgTBVppTweakSaturation->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppTweakScroll);
            // 
            // fcgLBVppTweakSaturation
            // 
            this->fcgLBVppTweakSaturation->AutoSize = true;
            this->fcgLBVppTweakSaturation->Location = System::Drawing::Point(11, 118);
            this->fcgLBVppTweakSaturation->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppTweakSaturation->Name = L"fcgLBVppTweakSaturation";
            this->fcgLBVppTweakSaturation->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppTweakSaturation->TabIndex = 110;
            this->fcgLBVppTweakSaturation->Text = L"彩度";
            // 
            // fcgTBVppTweakGamma
            // 
            this->fcgTBVppTweakGamma->AutoSize = false;
            this->fcgTBVppTweakGamma->LargeChange = 10;
            this->fcgTBVppTweakGamma->Location = System::Drawing::Point(75, 86);
            this->fcgTBVppTweakGamma->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppTweakGamma->Maximum = 500;
            this->fcgTBVppTweakGamma->Minimum = 1;
            this->fcgTBVppTweakGamma->Name = L"fcgTBVppTweakGamma";
            this->fcgTBVppTweakGamma->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppTweakGamma->TabIndex = 109;
            this->fcgTBVppTweakGamma->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppTweakGamma->Value = 100;
            this->fcgTBVppTweakGamma->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppTweakScroll);
            // 
            // fcgLBVppTweakGamma
            // 
            this->fcgLBVppTweakGamma->AutoSize = true;
            this->fcgLBVppTweakGamma->Location = System::Drawing::Point(11, 86);
            this->fcgLBVppTweakGamma->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppTweakGamma->Name = L"fcgLBVppTweakGamma";
            this->fcgLBVppTweakGamma->Size = System::Drawing::Size(40, 18);
            this->fcgLBVppTweakGamma->TabIndex = 108;
            this->fcgLBVppTweakGamma->Text = L"ガンマ";
            // 
            // fcgTBVppTweakContrast
            // 
            this->fcgTBVppTweakContrast->AutoSize = false;
            this->fcgTBVppTweakContrast->LargeChange = 10;
            this->fcgTBVppTweakContrast->Location = System::Drawing::Point(75, 55);
            this->fcgTBVppTweakContrast->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppTweakContrast->Maximum = 200;
            this->fcgTBVppTweakContrast->Minimum = -200;
            this->fcgTBVppTweakContrast->Name = L"fcgTBVppTweakContrast";
            this->fcgTBVppTweakContrast->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppTweakContrast->TabIndex = 107;
            this->fcgTBVppTweakContrast->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppTweakContrast->Value = 100;
            this->fcgTBVppTweakContrast->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppTweakScroll);
            // 
            // fcgLBVppTweakContrast
            // 
            this->fcgLBVppTweakContrast->AutoSize = true;
            this->fcgLBVppTweakContrast->Location = System::Drawing::Point(11, 55);
            this->fcgLBVppTweakContrast->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppTweakContrast->Name = L"fcgLBVppTweakContrast";
            this->fcgLBVppTweakContrast->Size = System::Drawing::Size(69, 18);
            this->fcgLBVppTweakContrast->TabIndex = 106;
            this->fcgLBVppTweakContrast->Text = L"コントラスト";
            // 
            // fcgTBVppTweakBrightness
            // 
            this->fcgTBVppTweakBrightness->AutoSize = false;
            this->fcgTBVppTweakBrightness->LargeChange = 10;
            this->fcgTBVppTweakBrightness->Location = System::Drawing::Point(75, 24);
            this->fcgTBVppTweakBrightness->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppTweakBrightness->Maximum = 100;
            this->fcgTBVppTweakBrightness->Minimum = -100;
            this->fcgTBVppTweakBrightness->Name = L"fcgTBVppTweakBrightness";
            this->fcgTBVppTweakBrightness->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppTweakBrightness->TabIndex = 105;
            this->fcgTBVppTweakBrightness->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppTweakBrightness->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppTweakScroll);
            // 
            // fcgNUVppTweakGamma
            // 
            this->fcgNUVppTweakGamma->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->fcgNUVppTweakGamma->Location = System::Drawing::Point(226, 86);
            this->fcgNUVppTweakGamma->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppTweakGamma->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
            this->fcgNUVppTweakGamma->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUVppTweakGamma->Name = L"fcgNUVppTweakGamma";
            this->fcgNUVppTweakGamma->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppTweakGamma->TabIndex = 104;
            this->fcgNUVppTweakGamma->Tag = L"chValue";
            this->fcgNUVppTweakGamma->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppTweakGamma->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            this->fcgNUVppTweakGamma->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppTweakValueChanged);
            // 
            // fcgNUVppTweakSaturation
            // 
            this->fcgNUVppTweakSaturation->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->fcgNUVppTweakSaturation->Location = System::Drawing::Point(226, 118);
            this->fcgNUVppTweakSaturation->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppTweakSaturation->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
            this->fcgNUVppTweakSaturation->Name = L"fcgNUVppTweakSaturation";
            this->fcgNUVppTweakSaturation->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppTweakSaturation->TabIndex = 103;
            this->fcgNUVppTweakSaturation->Tag = L"chValue";
            this->fcgNUVppTweakSaturation->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppTweakSaturation->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            this->fcgNUVppTweakSaturation->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppTweakValueChanged);
            // 
            // fcgNUVppTweakHue
            // 
            this->fcgNUVppTweakHue->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->fcgNUVppTweakHue->Location = System::Drawing::Point(226, 149);
            this->fcgNUVppTweakHue->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppTweakHue->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
            this->fcgNUVppTweakHue->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, System::Int32::MinValue });
            this->fcgNUVppTweakHue->Name = L"fcgNUVppTweakHue";
            this->fcgNUVppTweakHue->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppTweakHue->TabIndex = 102;
            this->fcgNUVppTweakHue->Tag = L"chValue";
            this->fcgNUVppTweakHue->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppTweakHue->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppTweakValueChanged);
            // 
            // fcgLBVppTweakBrightness
            // 
            this->fcgLBVppTweakBrightness->AutoSize = true;
            this->fcgLBVppTweakBrightness->Location = System::Drawing::Point(11, 24);
            this->fcgLBVppTweakBrightness->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppTweakBrightness->Name = L"fcgLBVppTweakBrightness";
            this->fcgLBVppTweakBrightness->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppTweakBrightness->TabIndex = 101;
            this->fcgLBVppTweakBrightness->Text = L"輝度";
            // 
            // fcgNUVppTweakContrast
            // 
            this->fcgNUVppTweakContrast->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->fcgNUVppTweakContrast->Location = System::Drawing::Point(226, 55);
            this->fcgNUVppTweakContrast->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppTweakContrast->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
            this->fcgNUVppTweakContrast->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, System::Int32::MinValue });
            this->fcgNUVppTweakContrast->Name = L"fcgNUVppTweakContrast";
            this->fcgNUVppTweakContrast->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppTweakContrast->TabIndex = 100;
            this->fcgNUVppTweakContrast->Tag = L"chValue";
            this->fcgNUVppTweakContrast->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppTweakContrast->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            this->fcgNUVppTweakContrast->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppTweakValueChanged);
            // 
            // fcgNUVppTweakBrightness
            // 
            this->fcgNUVppTweakBrightness->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->fcgNUVppTweakBrightness->Location = System::Drawing::Point(226, 24);
            this->fcgNUVppTweakBrightness->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppTweakBrightness->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
            this->fcgNUVppTweakBrightness->Name = L"fcgNUVppTweakBrightness";
            this->fcgNUVppTweakBrightness->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppTweakBrightness->TabIndex = 99;
            this->fcgNUVppTweakBrightness->Tag = L"chValue";
            this->fcgNUVppTweakBrightness->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppTweakBrightness->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppTweakValueChanged);
            // 
            // fcgCBVppPerfMonitor
            // 
            this->fcgCBVppPerfMonitor->AutoSize = true;
            this->fcgCBVppPerfMonitor->Location = System::Drawing::Point(15, 574);
            this->fcgCBVppPerfMonitor->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppPerfMonitor->Name = L"fcgCBVppPerfMonitor";
            this->fcgCBVppPerfMonitor->Size = System::Drawing::Size(140, 22);
            this->fcgCBVppPerfMonitor->TabIndex = 167;
            this->fcgCBVppPerfMonitor->Tag = L"chValue";
            this->fcgCBVppPerfMonitor->Text = L"パフォーマンスチェック";
            this->fcgCBVppPerfMonitor->UseVisualStyleBackColor = true;
            // 
            // fcggroupBoxVppDetailEnahance
            // 
            this->fcggroupBoxVppDetailEnahance->Controls->Add(this->fcgPNVppEdgelevel);
            this->fcggroupBoxVppDetailEnahance->Controls->Add(this->fcgCXVppDetailEnhance);
            this->fcggroupBoxVppDetailEnahance->Controls->Add(this->fcgPNVppUnsharp);
            this->fcggroupBoxVppDetailEnahance->Location = System::Drawing::Point(4, 249);
            this->fcggroupBoxVppDetailEnahance->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppDetailEnahance->Name = L"fcggroupBoxVppDetailEnahance";
            this->fcggroupBoxVppDetailEnahance->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppDetailEnahance->Size = System::Drawing::Size(400, 138);
            this->fcggroupBoxVppDetailEnahance->TabIndex = 66;
            this->fcggroupBoxVppDetailEnahance->TabStop = false;
            this->fcggroupBoxVppDetailEnahance->Text = L"ディテール・輪郭強調";
            // 
            // fcgPNVppEdgelevel
            // 
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgLBVppEdgelevelWhite);
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgNUVppEdgelevelWhite);
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgLBVppEdgelevelThreshold);
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgLBVppEdgelevelBlack);
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgLBVppEdgelevelStrength);
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgNUVppEdgelevelThreshold);
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgNUVppEdgelevelBlack);
            this->fcgPNVppEdgelevel->Controls->Add(this->fcgNUVppEdgelevelStrength);
            this->fcgPNVppEdgelevel->Controls->Add(this->label10);
            this->fcgPNVppEdgelevel->Controls->Add(this->numericUpDown4);
            this->fcgPNVppEdgelevel->Location = System::Drawing::Point(4, 54);
            this->fcgPNVppEdgelevel->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNVppEdgelevel->Name = L"fcgPNVppEdgelevel";
            this->fcgPNVppEdgelevel->Size = System::Drawing::Size(389, 76);
            this->fcgPNVppEdgelevel->TabIndex = 64;
            // 
            // fcgLBVppEdgelevelWhite
            // 
            this->fcgLBVppEdgelevelWhite->AutoSize = true;
            this->fcgLBVppEdgelevelWhite->Location = System::Drawing::Point(228, 46);
            this->fcgLBVppEdgelevelWhite->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppEdgelevelWhite->Name = L"fcgLBVppEdgelevelWhite";
            this->fcgLBVppEdgelevelWhite->Size = System::Drawing::Size(22, 18);
            this->fcgLBVppEdgelevelWhite->TabIndex = 19;
            this->fcgLBVppEdgelevelWhite->Text = L"白";
            // 
            // fcgNUVppEdgelevelWhite
            // 
            this->fcgNUVppEdgelevelWhite->DecimalPlaces = 1;
            this->fcgNUVppEdgelevelWhite->Location = System::Drawing::Point(299, 42);
            this->fcgNUVppEdgelevelWhite->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppEdgelevelWhite->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppEdgelevelWhite->Name = L"fcgNUVppEdgelevelWhite";
            this->fcgNUVppEdgelevelWhite->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppEdgelevelWhite->TabIndex = 18;
            this->fcgNUVppEdgelevelWhite->Tag = L"chValue";
            this->fcgNUVppEdgelevelWhite->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppEdgelevelWhite->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgLBVppEdgelevelThreshold
            // 
            this->fcgLBVppEdgelevelThreshold->AutoSize = true;
            this->fcgLBVppEdgelevelThreshold->Location = System::Drawing::Point(228, 11);
            this->fcgLBVppEdgelevelThreshold->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppEdgelevelThreshold->Name = L"fcgLBVppEdgelevelThreshold";
            this->fcgLBVppEdgelevelThreshold->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppEdgelevelThreshold->TabIndex = 17;
            this->fcgLBVppEdgelevelThreshold->Text = L"閾値";
            // 
            // fcgLBVppEdgelevelBlack
            // 
            this->fcgLBVppEdgelevelBlack->AutoSize = true;
            this->fcgLBVppEdgelevelBlack->Location = System::Drawing::Point(10, 46);
            this->fcgLBVppEdgelevelBlack->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppEdgelevelBlack->Name = L"fcgLBVppEdgelevelBlack";
            this->fcgLBVppEdgelevelBlack->Size = System::Drawing::Size(22, 18);
            this->fcgLBVppEdgelevelBlack->TabIndex = 16;
            this->fcgLBVppEdgelevelBlack->Text = L"黒";
            // 
            // fcgLBVppEdgelevelStrength
            // 
            this->fcgLBVppEdgelevelStrength->AutoSize = true;
            this->fcgLBVppEdgelevelStrength->Location = System::Drawing::Point(10, 12);
            this->fcgLBVppEdgelevelStrength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppEdgelevelStrength->Name = L"fcgLBVppEdgelevelStrength";
            this->fcgLBVppEdgelevelStrength->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppEdgelevelStrength->TabIndex = 15;
            this->fcgLBVppEdgelevelStrength->Text = L"特性";
            // 
            // fcgNUVppEdgelevelThreshold
            // 
            this->fcgNUVppEdgelevelThreshold->Location = System::Drawing::Point(299, 9);
            this->fcgNUVppEdgelevelThreshold->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppEdgelevelThreshold->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
            this->fcgNUVppEdgelevelThreshold->Name = L"fcgNUVppEdgelevelThreshold";
            this->fcgNUVppEdgelevelThreshold->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppEdgelevelThreshold->TabIndex = 14;
            this->fcgNUVppEdgelevelThreshold->Tag = L"chValue";
            this->fcgNUVppEdgelevelThreshold->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppEdgelevelThreshold->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppEdgelevelBlack
            // 
            this->fcgNUVppEdgelevelBlack->DecimalPlaces = 1;
            this->fcgNUVppEdgelevelBlack->Location = System::Drawing::Point(85, 42);
            this->fcgNUVppEdgelevelBlack->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppEdgelevelBlack->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppEdgelevelBlack->Name = L"fcgNUVppEdgelevelBlack";
            this->fcgNUVppEdgelevelBlack->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppEdgelevelBlack->TabIndex = 13;
            this->fcgNUVppEdgelevelBlack->Tag = L"chValue";
            this->fcgNUVppEdgelevelBlack->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppEdgelevelBlack->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppEdgelevelStrength
            // 
            this->fcgNUVppEdgelevelStrength->Location = System::Drawing::Point(85, 9);
            this->fcgNUVppEdgelevelStrength->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppEdgelevelStrength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppEdgelevelStrength->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, System::Int32::MinValue });
            this->fcgNUVppEdgelevelStrength->Name = L"fcgNUVppEdgelevelStrength";
            this->fcgNUVppEdgelevelStrength->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppEdgelevelStrength->TabIndex = 12;
            this->fcgNUVppEdgelevelStrength->Tag = L"chValue";
            this->fcgNUVppEdgelevelStrength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppEdgelevelStrength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(86, 82);
            this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(36, 18);
            this->label10->TabIndex = 11;
            this->label10->Text = L"閾値";
            // 
            // numericUpDown4
            // 
            this->numericUpDown4->Location = System::Drawing::Point(161, 80);
            this->numericUpDown4->Margin = System::Windows::Forms::Padding(4);
            this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
            this->numericUpDown4->Name = L"numericUpDown4";
            this->numericUpDown4->Size = System::Drawing::Size(75, 25);
            this->numericUpDown4->TabIndex = 8;
            this->numericUpDown4->Tag = L"chValue";
            this->numericUpDown4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // fcgCXVppDetailEnhance
            // 
            this->fcgCXVppDetailEnhance->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVppDetailEnhance->FormattingEnabled = true;
            this->fcgCXVppDetailEnhance->Location = System::Drawing::Point(32, 25);
            this->fcgCXVppDetailEnhance->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXVppDetailEnhance->Name = L"fcgCXVppDetailEnhance";
            this->fcgCXVppDetailEnhance->Size = System::Drawing::Size(238, 26);
            this->fcgCXVppDetailEnhance->TabIndex = 63;
            this->fcgCXVppDetailEnhance->Tag = L"chValue";
            this->fcgCXVppDetailEnhance->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcgPNVppUnsharp
            // 
            this->fcgPNVppUnsharp->Controls->Add(this->fcgLBVppUnsharpThreshold);
            this->fcgPNVppUnsharp->Controls->Add(this->fcgLBVppUnsharpWeight);
            this->fcgPNVppUnsharp->Controls->Add(this->fcgLBVppUnsharpRadius);
            this->fcgPNVppUnsharp->Controls->Add(this->fcgNUVppUnsharpThreshold);
            this->fcgPNVppUnsharp->Controls->Add(this->fcgNUVppUnsharpWeight);
            this->fcgPNVppUnsharp->Controls->Add(this->fcgNUVppUnsharpRadius);
            this->fcgPNVppUnsharp->Location = System::Drawing::Point(4, 54);
            this->fcgPNVppUnsharp->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNVppUnsharp->Name = L"fcgPNVppUnsharp";
            this->fcgPNVppUnsharp->Size = System::Drawing::Size(388, 76);
            this->fcgPNVppUnsharp->TabIndex = 65;
            // 
            // fcgLBVppUnsharpThreshold
            // 
            this->fcgLBVppUnsharpThreshold->AutoSize = true;
            this->fcgLBVppUnsharpThreshold->Location = System::Drawing::Point(230, 11);
            this->fcgLBVppUnsharpThreshold->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppUnsharpThreshold->Name = L"fcgLBVppUnsharpThreshold";
            this->fcgLBVppUnsharpThreshold->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppUnsharpThreshold->TabIndex = 11;
            this->fcgLBVppUnsharpThreshold->Text = L"閾値";
            // 
            // fcgLBVppUnsharpWeight
            // 
            this->fcgLBVppUnsharpWeight->AutoSize = true;
            this->fcgLBVppUnsharpWeight->Location = System::Drawing::Point(12, 46);
            this->fcgLBVppUnsharpWeight->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppUnsharpWeight->Name = L"fcgLBVppUnsharpWeight";
            this->fcgLBVppUnsharpWeight->Size = System::Drawing::Size(32, 18);
            this->fcgLBVppUnsharpWeight->TabIndex = 10;
            this->fcgLBVppUnsharpWeight->Text = L"強さ";
            // 
            // fcgLBVppUnsharpRadius
            // 
            this->fcgLBVppUnsharpRadius->AutoSize = true;
            this->fcgLBVppUnsharpRadius->Location = System::Drawing::Point(12, 12);
            this->fcgLBVppUnsharpRadius->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppUnsharpRadius->Name = L"fcgLBVppUnsharpRadius";
            this->fcgLBVppUnsharpRadius->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppUnsharpRadius->TabIndex = 9;
            this->fcgLBVppUnsharpRadius->Text = L"半径";
            // 
            // fcgNUVppUnsharpThreshold
            // 
            this->fcgNUVppUnsharpThreshold->Location = System::Drawing::Point(305, 9);
            this->fcgNUVppUnsharpThreshold->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppUnsharpThreshold->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
            this->fcgNUVppUnsharpThreshold->Name = L"fcgNUVppUnsharpThreshold";
            this->fcgNUVppUnsharpThreshold->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppUnsharpThreshold->TabIndex = 8;
            this->fcgNUVppUnsharpThreshold->Tag = L"chValue";
            this->fcgNUVppUnsharpThreshold->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppUnsharpThreshold->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppUnsharpWeight
            // 
            this->fcgNUVppUnsharpWeight->DecimalPlaces = 1;
            this->fcgNUVppUnsharpWeight->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
            this->fcgNUVppUnsharpWeight->Location = System::Drawing::Point(88, 42);
            this->fcgNUVppUnsharpWeight->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppUnsharpWeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->fcgNUVppUnsharpWeight->Name = L"fcgNUVppUnsharpWeight";
            this->fcgNUVppUnsharpWeight->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppUnsharpWeight->TabIndex = 7;
            this->fcgNUVppUnsharpWeight->Tag = L"chValue";
            this->fcgNUVppUnsharpWeight->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppUnsharpWeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppUnsharpRadius
            // 
            this->fcgNUVppUnsharpRadius->Location = System::Drawing::Point(88, 9);
            this->fcgNUVppUnsharpRadius->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppUnsharpRadius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
            this->fcgNUVppUnsharpRadius->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUVppUnsharpRadius->Name = L"fcgNUVppUnsharpRadius";
            this->fcgNUVppUnsharpRadius->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppUnsharpRadius->TabIndex = 6;
            this->fcgNUVppUnsharpRadius->Tag = L"chValue";
            this->fcgNUVppUnsharpRadius->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppUnsharpRadius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
            // 
            // fcgCBVppAfsEnable
            // 
            this->fcgCBVppAfsEnable->AutoSize = true;
            this->fcgCBVppAfsEnable->Location = System::Drawing::Point(462, 3);
            this->fcgCBVppAfsEnable->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppAfsEnable->Name = L"fcgCBVppAfsEnable";
            this->fcgCBVppAfsEnable->Size = System::Drawing::Size(137, 22);
            this->fcgCBVppAfsEnable->TabIndex = 15;
            this->fcgCBVppAfsEnable->Tag = L"chValue";
            this->fcgCBVppAfsEnable->Text = L"自動フィールドシフト";
            this->fcgCBVppAfsEnable->UseVisualStyleBackColor = true;
            this->fcgCBVppAfsEnable->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcggroupBoxVppAfs
            // 
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgTBVppAfsThreCMotion);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsThreCMotion);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgTBVppAfsThreYMotion);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsThreYmotion);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgTBVppAfsThreDeint);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsThreDeint);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgTBVppAfsThreShift);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsThreShift);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgTBVppAfsCoeffShift);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsCoeffShift);
            this->fcggroupBoxVppAfs->Controls->Add(this->label20);
            this->fcggroupBoxVppAfs->Controls->Add(this->label19);
            this->fcggroupBoxVppAfs->Controls->Add(this->label4);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsUp);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsRight);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsLeft);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsBottom);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsUp);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgTBVppAfsMethodSwitch);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgCBVppAfs24fps);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgCBVppAfsTune);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgCBVppAfsSmooth);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgCBVppAfsDrop);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgCBVppAfsShift);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsAnalyze);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsThreCMotion);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsThreShift);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsThreDeint);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsThreYMotion);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgLBVppAfsMethodSwitch);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgCXVppAfsAnalyze);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsCoeffShift);
            this->fcggroupBoxVppAfs->Controls->Add(this->fcgNUVppAfsMethodSwitch);
            this->fcggroupBoxVppAfs->Location = System::Drawing::Point(448, 6);
            this->fcggroupBoxVppAfs->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppAfs->Name = L"fcggroupBoxVppAfs";
            this->fcggroupBoxVppAfs->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppAfs->Size = System::Drawing::Size(308, 400);
            this->fcggroupBoxVppAfs->TabIndex = 14;
            this->fcggroupBoxVppAfs->TabStop = false;
            // 
            // fcgTBVppAfsThreCMotion
            // 
            this->fcgTBVppAfsThreCMotion->AutoSize = false;
            this->fcgTBVppAfsThreCMotion->Location = System::Drawing::Point(76, 245);
            this->fcgTBVppAfsThreCMotion->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppAfsThreCMotion->Maximum = 1024;
            this->fcgTBVppAfsThreCMotion->Name = L"fcgTBVppAfsThreCMotion";
            this->fcgTBVppAfsThreCMotion->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppAfsThreCMotion->TabIndex = 100;
            this->fcgTBVppAfsThreCMotion->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppAfsThreCMotion->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppAfsScroll);
            // 
            // fcgLBVppAfsThreCMotion
            // 
            this->fcgLBVppAfsThreCMotion->AutoSize = true;
            this->fcgLBVppAfsThreCMotion->Location = System::Drawing::Point(12, 245);
            this->fcgLBVppAfsThreCMotion->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsThreCMotion->Name = L"fcgLBVppAfsThreCMotion";
            this->fcgLBVppAfsThreCMotion->Size = System::Drawing::Size(42, 18);
            this->fcgLBVppAfsThreCMotion->TabIndex = 99;
            this->fcgLBVppAfsThreCMotion->Text = L"C動き";
            // 
            // fcgTBVppAfsThreYMotion
            // 
            this->fcgTBVppAfsThreYMotion->AutoSize = false;
            this->fcgTBVppAfsThreYMotion->Location = System::Drawing::Point(76, 214);
            this->fcgTBVppAfsThreYMotion->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppAfsThreYMotion->Maximum = 1024;
            this->fcgTBVppAfsThreYMotion->Name = L"fcgTBVppAfsThreYMotion";
            this->fcgTBVppAfsThreYMotion->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppAfsThreYMotion->TabIndex = 98;
            this->fcgTBVppAfsThreYMotion->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppAfsThreYMotion->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppAfsScroll);
            // 
            // fcgLBVppAfsThreYmotion
            // 
            this->fcgLBVppAfsThreYmotion->AutoSize = true;
            this->fcgLBVppAfsThreYmotion->Location = System::Drawing::Point(12, 214);
            this->fcgLBVppAfsThreYmotion->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsThreYmotion->Name = L"fcgLBVppAfsThreYmotion";
            this->fcgLBVppAfsThreYmotion->Size = System::Drawing::Size(42, 18);
            this->fcgLBVppAfsThreYmotion->TabIndex = 97;
            this->fcgLBVppAfsThreYmotion->Text = L"Y動き";
            // 
            // fcgTBVppAfsThreDeint
            // 
            this->fcgTBVppAfsThreDeint->AutoSize = false;
            this->fcgTBVppAfsThreDeint->Location = System::Drawing::Point(76, 182);
            this->fcgTBVppAfsThreDeint->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppAfsThreDeint->Maximum = 1024;
            this->fcgTBVppAfsThreDeint->Name = L"fcgTBVppAfsThreDeint";
            this->fcgTBVppAfsThreDeint->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppAfsThreDeint->TabIndex = 96;
            this->fcgTBVppAfsThreDeint->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppAfsThreDeint->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppAfsScroll);
            // 
            // fcgLBVppAfsThreDeint
            // 
            this->fcgLBVppAfsThreDeint->AutoSize = true;
            this->fcgLBVppAfsThreDeint->Location = System::Drawing::Point(12, 182);
            this->fcgLBVppAfsThreDeint->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsThreDeint->Name = L"fcgLBVppAfsThreDeint";
            this->fcgLBVppAfsThreDeint->Size = System::Drawing::Size(62, 18);
            this->fcgLBVppAfsThreDeint->TabIndex = 95;
            this->fcgLBVppAfsThreDeint->Text = L"縞(解除)";
            // 
            // fcgTBVppAfsThreShift
            // 
            this->fcgTBVppAfsThreShift->AutoSize = false;
            this->fcgTBVppAfsThreShift->Location = System::Drawing::Point(76, 151);
            this->fcgTBVppAfsThreShift->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppAfsThreShift->Maximum = 1024;
            this->fcgTBVppAfsThreShift->Name = L"fcgTBVppAfsThreShift";
            this->fcgTBVppAfsThreShift->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppAfsThreShift->TabIndex = 94;
            this->fcgTBVppAfsThreShift->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppAfsThreShift->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppAfsScroll);
            // 
            // fcgLBVppAfsThreShift
            // 
            this->fcgLBVppAfsThreShift->AutoSize = true;
            this->fcgLBVppAfsThreShift->Location = System::Drawing::Point(12, 151);
            this->fcgLBVppAfsThreShift->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsThreShift->Name = L"fcgLBVppAfsThreShift";
            this->fcgLBVppAfsThreShift->Size = System::Drawing::Size(55, 18);
            this->fcgLBVppAfsThreShift->TabIndex = 93;
            this->fcgLBVppAfsThreShift->Text = L"縞(ｼﾌﾄ)";
            // 
            // fcgTBVppAfsCoeffShift
            // 
            this->fcgTBVppAfsCoeffShift->AutoSize = false;
            this->fcgTBVppAfsCoeffShift->Location = System::Drawing::Point(76, 120);
            this->fcgTBVppAfsCoeffShift->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppAfsCoeffShift->Maximum = 256;
            this->fcgTBVppAfsCoeffShift->Name = L"fcgTBVppAfsCoeffShift";
            this->fcgTBVppAfsCoeffShift->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppAfsCoeffShift->TabIndex = 92;
            this->fcgTBVppAfsCoeffShift->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppAfsCoeffShift->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppAfsScroll);
            // 
            // fcgLBVppAfsCoeffShift
            // 
            this->fcgLBVppAfsCoeffShift->AutoSize = true;
            this->fcgLBVppAfsCoeffShift->Location = System::Drawing::Point(12, 120);
            this->fcgLBVppAfsCoeffShift->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsCoeffShift->Name = L"fcgLBVppAfsCoeffShift";
            this->fcgLBVppAfsCoeffShift->Size = System::Drawing::Size(50, 18);
            this->fcgLBVppAfsCoeffShift->TabIndex = 91;
            this->fcgLBVppAfsCoeffShift->Text = L"判定比";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Location = System::Drawing::Point(205, 58);
            this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(22, 18);
            this->label20->TabIndex = 90;
            this->label20->Text = L"右";
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Location = System::Drawing::Point(72, 58);
            this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(22, 18);
            this->label19->TabIndex = 89;
            this->label19->Text = L"左";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(205, 25);
            this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(22, 18);
            this->label4->TabIndex = 88;
            this->label4->Text = L"下";
            // 
            // fcgLBVppAfsUp
            // 
            this->fcgLBVppAfsUp->AutoSize = true;
            this->fcgLBVppAfsUp->Location = System::Drawing::Point(72, 25);
            this->fcgLBVppAfsUp->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsUp->Name = L"fcgLBVppAfsUp";
            this->fcgLBVppAfsUp->Size = System::Drawing::Size(22, 18);
            this->fcgLBVppAfsUp->TabIndex = 87;
            this->fcgLBVppAfsUp->Text = L"上";
            // 
            // fcgNUVppAfsRight
            // 
            this->fcgNUVppAfsRight->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
            this->fcgNUVppAfsRight->Location = System::Drawing::Point(228, 55);
            this->fcgNUVppAfsRight->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsRight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8192, 0, 0, 0 });
            this->fcgNUVppAfsRight->Name = L"fcgNUVppAfsRight";
            this->fcgNUVppAfsRight->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsRight->TabIndex = 86;
            this->fcgNUVppAfsRight->Tag = L"chValue";
            this->fcgNUVppAfsRight->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppAfsLeft
            // 
            this->fcgNUVppAfsLeft->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
            this->fcgNUVppAfsLeft->Location = System::Drawing::Point(98, 55);
            this->fcgNUVppAfsLeft->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsLeft->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8192, 0, 0, 0 });
            this->fcgNUVppAfsLeft->Name = L"fcgNUVppAfsLeft";
            this->fcgNUVppAfsLeft->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsLeft->TabIndex = 85;
            this->fcgNUVppAfsLeft->Tag = L"chValue";
            this->fcgNUVppAfsLeft->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppAfsBottom
            // 
            this->fcgNUVppAfsBottom->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
            this->fcgNUVppAfsBottom->Location = System::Drawing::Point(228, 22);
            this->fcgNUVppAfsBottom->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsBottom->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
            this->fcgNUVppAfsBottom->Name = L"fcgNUVppAfsBottom";
            this->fcgNUVppAfsBottom->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsBottom->TabIndex = 84;
            this->fcgNUVppAfsBottom->Tag = L"chValue";
            this->fcgNUVppAfsBottom->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppAfsUp
            // 
            this->fcgNUVppAfsUp->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
            this->fcgNUVppAfsUp->Location = System::Drawing::Point(98, 22);
            this->fcgNUVppAfsUp->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsUp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4096, 0, 0, 0 });
            this->fcgNUVppAfsUp->Name = L"fcgNUVppAfsUp";
            this->fcgNUVppAfsUp->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsUp->TabIndex = 83;
            this->fcgNUVppAfsUp->Tag = L"chValue";
            this->fcgNUVppAfsUp->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgTBVppAfsMethodSwitch
            // 
            this->fcgTBVppAfsMethodSwitch->AutoSize = false;
            this->fcgTBVppAfsMethodSwitch->Location = System::Drawing::Point(76, 89);
            this->fcgTBVppAfsMethodSwitch->Margin = System::Windows::Forms::Padding(4);
            this->fcgTBVppAfsMethodSwitch->Maximum = 256;
            this->fcgTBVppAfsMethodSwitch->Name = L"fcgTBVppAfsMethodSwitch";
            this->fcgTBVppAfsMethodSwitch->Size = System::Drawing::Size(144, 22);
            this->fcgTBVppAfsMethodSwitch->TabIndex = 82;
            this->fcgTBVppAfsMethodSwitch->TickStyle = System::Windows::Forms::TickStyle::None;
            this->fcgTBVppAfsMethodSwitch->Scroll += gcnew System::EventHandler(this, &frmConfig::fcgTBVppAfsScroll);
            // 
            // fcgCBVppAfs24fps
            // 
            this->fcgCBVppAfs24fps->AutoSize = true;
            this->fcgCBVppAfs24fps->Location = System::Drawing::Point(188, 310);
            this->fcgCBVppAfs24fps->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppAfs24fps->Name = L"fcgCBVppAfs24fps";
            this->fcgCBVppAfs24fps->Size = System::Drawing::Size(83, 22);
            this->fcgCBVppAfs24fps->TabIndex = 81;
            this->fcgCBVppAfs24fps->Tag = L"chValue";
            this->fcgCBVppAfs24fps->Text = L"24fps化";
            this->fcgCBVppAfs24fps->UseVisualStyleBackColor = true;
            // 
            // fcgCBVppAfsTune
            // 
            this->fcgCBVppAfsTune->AutoSize = true;
            this->fcgCBVppAfsTune->Location = System::Drawing::Point(188, 369);
            this->fcgCBVppAfsTune->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppAfsTune->Name = L"fcgCBVppAfsTune";
            this->fcgCBVppAfsTune->Size = System::Drawing::Size(90, 22);
            this->fcgCBVppAfsTune->TabIndex = 80;
            this->fcgCBVppAfsTune->Tag = L"chValue";
            this->fcgCBVppAfsTune->Text = L"調整モード";
            this->fcgCBVppAfsTune->UseVisualStyleBackColor = true;
            // 
            // fcgCBVppAfsSmooth
            // 
            this->fcgCBVppAfsSmooth->AutoSize = true;
            this->fcgCBVppAfsSmooth->Location = System::Drawing::Point(15, 369);
            this->fcgCBVppAfsSmooth->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppAfsSmooth->Name = L"fcgCBVppAfsSmooth";
            this->fcgCBVppAfsSmooth->Size = System::Drawing::Size(96, 22);
            this->fcgCBVppAfsSmooth->TabIndex = 79;
            this->fcgCBVppAfsSmooth->Tag = L"chValue";
            this->fcgCBVppAfsSmooth->Text = L"スムージング";
            this->fcgCBVppAfsSmooth->UseVisualStyleBackColor = true;
            // 
            // fcgCBVppAfsDrop
            // 
            this->fcgCBVppAfsDrop->AutoSize = true;
            this->fcgCBVppAfsDrop->Location = System::Drawing::Point(15, 339);
            this->fcgCBVppAfsDrop->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppAfsDrop->Name = L"fcgCBVppAfsDrop";
            this->fcgCBVppAfsDrop->Size = System::Drawing::Size(69, 22);
            this->fcgCBVppAfsDrop->TabIndex = 78;
            this->fcgCBVppAfsDrop->Tag = L"chValue";
            this->fcgCBVppAfsDrop->Text = L"間引き";
            this->fcgCBVppAfsDrop->UseVisualStyleBackColor = true;
            // 
            // fcgCBVppAfsShift
            // 
            this->fcgCBVppAfsShift->AutoSize = true;
            this->fcgCBVppAfsShift->Location = System::Drawing::Point(15, 310);
            this->fcgCBVppAfsShift->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppAfsShift->Name = L"fcgCBVppAfsShift";
            this->fcgCBVppAfsShift->Size = System::Drawing::Size(109, 22);
            this->fcgCBVppAfsShift->TabIndex = 77;
            this->fcgCBVppAfsShift->Tag = L"chValue";
            this->fcgCBVppAfsShift->Text = L"フィールドシフト";
            this->fcgCBVppAfsShift->UseVisualStyleBackColor = true;
            // 
            // fcgLBVppAfsAnalyze
            // 
            this->fcgLBVppAfsAnalyze->AutoSize = true;
            this->fcgLBVppAfsAnalyze->Location = System::Drawing::Point(12, 280);
            this->fcgLBVppAfsAnalyze->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsAnalyze->Name = L"fcgLBVppAfsAnalyze";
            this->fcgLBVppAfsAnalyze->Size = System::Drawing::Size(51, 18);
            this->fcgLBVppAfsAnalyze->TabIndex = 76;
            this->fcgLBVppAfsAnalyze->Text = L"解除Lv";
            // 
            // fcgNUVppAfsThreCMotion
            // 
            this->fcgNUVppAfsThreCMotion->Location = System::Drawing::Point(228, 245);
            this->fcgNUVppAfsThreCMotion->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsThreCMotion->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1024, 0, 0, 0 });
            this->fcgNUVppAfsThreCMotion->Name = L"fcgNUVppAfsThreCMotion";
            this->fcgNUVppAfsThreCMotion->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsThreCMotion->TabIndex = 69;
            this->fcgNUVppAfsThreCMotion->Tag = L"chValue";
            this->fcgNUVppAfsThreCMotion->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppAfsThreCMotion->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppAfsValueChanged);
            // 
            // fcgNUVppAfsThreShift
            // 
            this->fcgNUVppAfsThreShift->Location = System::Drawing::Point(228, 151);
            this->fcgNUVppAfsThreShift->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsThreShift->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1024, 0, 0, 0 });
            this->fcgNUVppAfsThreShift->Name = L"fcgNUVppAfsThreShift";
            this->fcgNUVppAfsThreShift->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsThreShift->TabIndex = 68;
            this->fcgNUVppAfsThreShift->Tag = L"chValue";
            this->fcgNUVppAfsThreShift->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppAfsThreShift->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppAfsValueChanged);
            // 
            // fcgNUVppAfsThreDeint
            // 
            this->fcgNUVppAfsThreDeint->Location = System::Drawing::Point(228, 182);
            this->fcgNUVppAfsThreDeint->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsThreDeint->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1024, 0, 0, 0 });
            this->fcgNUVppAfsThreDeint->Name = L"fcgNUVppAfsThreDeint";
            this->fcgNUVppAfsThreDeint->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsThreDeint->TabIndex = 67;
            this->fcgNUVppAfsThreDeint->Tag = L"chValue";
            this->fcgNUVppAfsThreDeint->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppAfsThreDeint->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppAfsValueChanged);
            // 
            // fcgNUVppAfsThreYMotion
            // 
            this->fcgNUVppAfsThreYMotion->Location = System::Drawing::Point(228, 214);
            this->fcgNUVppAfsThreYMotion->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsThreYMotion->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1024, 0, 0, 0 });
            this->fcgNUVppAfsThreYMotion->Name = L"fcgNUVppAfsThreYMotion";
            this->fcgNUVppAfsThreYMotion->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsThreYMotion->TabIndex = 66;
            this->fcgNUVppAfsThreYMotion->Tag = L"chValue";
            this->fcgNUVppAfsThreYMotion->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppAfsThreYMotion->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppAfsValueChanged);
            // 
            // fcgLBVppAfsMethodSwitch
            // 
            this->fcgLBVppAfsMethodSwitch->AutoSize = true;
            this->fcgLBVppAfsMethodSwitch->Location = System::Drawing::Point(12, 89);
            this->fcgLBVppAfsMethodSwitch->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppAfsMethodSwitch->Name = L"fcgLBVppAfsMethodSwitch";
            this->fcgLBVppAfsMethodSwitch->Size = System::Drawing::Size(50, 18);
            this->fcgLBVppAfsMethodSwitch->TabIndex = 65;
            this->fcgLBVppAfsMethodSwitch->Text = L"切替点";
            // 
            // fcgCXVppAfsAnalyze
            // 
            this->fcgCXVppAfsAnalyze->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVppAfsAnalyze->FormattingEnabled = true;
            this->fcgCXVppAfsAnalyze->Location = System::Drawing::Point(76, 276);
            this->fcgCXVppAfsAnalyze->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXVppAfsAnalyze->Name = L"fcgCXVppAfsAnalyze";
            this->fcgCXVppAfsAnalyze->Size = System::Drawing::Size(225, 26);
            this->fcgCXVppAfsAnalyze->TabIndex = 63;
            this->fcgCXVppAfsAnalyze->Tag = L"chValue";
            // 
            // fcgNUVppAfsCoeffShift
            // 
            this->fcgNUVppAfsCoeffShift->Location = System::Drawing::Point(228, 120);
            this->fcgNUVppAfsCoeffShift->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsCoeffShift->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 256, 0, 0, 0 });
            this->fcgNUVppAfsCoeffShift->Name = L"fcgNUVppAfsCoeffShift";
            this->fcgNUVppAfsCoeffShift->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsCoeffShift->TabIndex = 5;
            this->fcgNUVppAfsCoeffShift->Tag = L"chValue";
            this->fcgNUVppAfsCoeffShift->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppAfsCoeffShift->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppAfsValueChanged);
            // 
            // fcgNUVppAfsMethodSwitch
            // 
            this->fcgNUVppAfsMethodSwitch->Location = System::Drawing::Point(228, 89);
            this->fcgNUVppAfsMethodSwitch->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppAfsMethodSwitch->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 256, 0, 0, 0 });
            this->fcgNUVppAfsMethodSwitch->Name = L"fcgNUVppAfsMethodSwitch";
            this->fcgNUVppAfsMethodSwitch->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppAfsMethodSwitch->TabIndex = 4;
            this->fcgNUVppAfsMethodSwitch->Tag = L"chValue";
            this->fcgNUVppAfsMethodSwitch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppAfsMethodSwitch->ValueChanged += gcnew System::EventHandler(this, &frmConfig::fcgNUVppAfsValueChanged);
            // 
            // fcgCBVppDebandEnable
            // 
            this->fcgCBVppDebandEnable->AutoSize = true;
            this->fcgCBVppDebandEnable->Location = System::Drawing::Point(15, 388);
            this->fcgCBVppDebandEnable->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppDebandEnable->Name = L"fcgCBVppDebandEnable";
            this->fcgCBVppDebandEnable->Size = System::Drawing::Size(120, 22);
            this->fcgCBVppDebandEnable->TabIndex = 13;
            this->fcgCBVppDebandEnable->Tag = L"chValue";
            this->fcgCBVppDebandEnable->Text = L"バンディング低減";
            this->fcgCBVppDebandEnable->UseVisualStyleBackColor = true;
            this->fcgCBVppDebandEnable->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcggroupBoxVppDeband
            // 
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgCBVppDebandRandEachFrame);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgCBVppDebandBlurFirst);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandSample);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandDitherC);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandDitherY);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandDither);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandThreCr);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandThreCb);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandThreY);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgNUVppDebandDitherC);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgNUVppDebandDitherY);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgNUVppDebandThreCr);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgNUVppDebandThreCb);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandThreshold);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgLBVppDebandRange);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgCXVppDebandSample);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgNUVppDebandThreY);
            this->fcggroupBoxVppDeband->Controls->Add(this->fcgNUVppDebandRange);
            this->fcggroupBoxVppDeband->Location = System::Drawing::Point(4, 386);
            this->fcggroupBoxVppDeband->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppDeband->Name = L"fcggroupBoxVppDeband";
            this->fcggroupBoxVppDeband->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppDeband->Size = System::Drawing::Size(400, 180);
            this->fcggroupBoxVppDeband->TabIndex = 12;
            this->fcggroupBoxVppDeband->TabStop = false;
            // 
            // fcgCBVppDebandRandEachFrame
            // 
            this->fcgCBVppDebandRandEachFrame->AutoSize = true;
            this->fcgCBVppDebandRandEachFrame->Location = System::Drawing::Point(206, 152);
            this->fcgCBVppDebandRandEachFrame->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppDebandRandEachFrame->Name = L"fcgCBVppDebandRandEachFrame";
            this->fcgCBVppDebandRandEachFrame->Size = System::Drawing::Size(153, 22);
            this->fcgCBVppDebandRandEachFrame->TabIndex = 78;
            this->fcgCBVppDebandRandEachFrame->Tag = L"chValue";
            this->fcgCBVppDebandRandEachFrame->Text = L"毎フレーム乱数を生成";
            this->fcgCBVppDebandRandEachFrame->UseVisualStyleBackColor = true;
            // 
            // fcgCBVppDebandBlurFirst
            // 
            this->fcgCBVppDebandBlurFirst->AutoSize = true;
            this->fcgCBVppDebandBlurFirst->Location = System::Drawing::Point(20, 152);
            this->fcgCBVppDebandBlurFirst->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppDebandBlurFirst->Name = L"fcgCBVppDebandBlurFirst";
            this->fcgCBVppDebandBlurFirst->Size = System::Drawing::Size(126, 22);
            this->fcgCBVppDebandBlurFirst->TabIndex = 77;
            this->fcgCBVppDebandBlurFirst->Tag = L"chValue";
            this->fcgCBVppDebandBlurFirst->Text = L"ブラー処理を先に";
            this->fcgCBVppDebandBlurFirst->UseVisualStyleBackColor = true;
            // 
            // fcgLBVppDebandSample
            // 
            this->fcgLBVppDebandSample->AutoSize = true;
            this->fcgLBVppDebandSample->Location = System::Drawing::Point(16, 121);
            this->fcgLBVppDebandSample->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandSample->Name = L"fcgLBVppDebandSample";
            this->fcgLBVppDebandSample->Size = System::Drawing::Size(57, 18);
            this->fcgLBVppDebandSample->TabIndex = 76;
            this->fcgLBVppDebandSample->Text = L"sample";
            // 
            // fcgLBVppDebandDitherC
            // 
            this->fcgLBVppDebandDitherC->AutoSize = true;
            this->fcgLBVppDebandDitherC->Location = System::Drawing::Point(184, 90);
            this->fcgLBVppDebandDitherC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandDitherC->Name = L"fcgLBVppDebandDitherC";
            this->fcgLBVppDebandDitherC->Size = System::Drawing::Size(17, 18);
            this->fcgLBVppDebandDitherC->TabIndex = 75;
            this->fcgLBVppDebandDitherC->Text = L"C";
            // 
            // fcgLBVppDebandDitherY
            // 
            this->fcgLBVppDebandDitherY->AutoSize = true;
            this->fcgLBVppDebandDitherY->Location = System::Drawing::Point(71, 90);
            this->fcgLBVppDebandDitherY->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandDitherY->Name = L"fcgLBVppDebandDitherY";
            this->fcgLBVppDebandDitherY->Size = System::Drawing::Size(17, 18);
            this->fcgLBVppDebandDitherY->TabIndex = 74;
            this->fcgLBVppDebandDitherY->Text = L"Y";
            // 
            // fcgLBVppDebandDither
            // 
            this->fcgLBVppDebandDither->AutoSize = true;
            this->fcgLBVppDebandDither->Location = System::Drawing::Point(16, 90);
            this->fcgLBVppDebandDither->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandDither->Name = L"fcgLBVppDebandDither";
            this->fcgLBVppDebandDither->Size = System::Drawing::Size(49, 18);
            this->fcgLBVppDebandDither->TabIndex = 73;
            this->fcgLBVppDebandDither->Text = L"dither";
            // 
            // fcgLBVppDebandThreCr
            // 
            this->fcgLBVppDebandThreCr->AutoSize = true;
            this->fcgLBVppDebandThreCr->Location = System::Drawing::Point(291, 61);
            this->fcgLBVppDebandThreCr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandThreCr->Name = L"fcgLBVppDebandThreCr";
            this->fcgLBVppDebandThreCr->Size = System::Drawing::Size(23, 18);
            this->fcgLBVppDebandThreCr->TabIndex = 72;
            this->fcgLBVppDebandThreCr->Text = L"Cr";
            // 
            // fcgLBVppDebandThreCb
            // 
            this->fcgLBVppDebandThreCb->AutoSize = true;
            this->fcgLBVppDebandThreCb->Location = System::Drawing::Point(178, 61);
            this->fcgLBVppDebandThreCb->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandThreCb->Name = L"fcgLBVppDebandThreCb";
            this->fcgLBVppDebandThreCb->Size = System::Drawing::Size(26, 18);
            this->fcgLBVppDebandThreCb->TabIndex = 71;
            this->fcgLBVppDebandThreCb->Text = L"Cb";
            // 
            // fcgLBVppDebandThreY
            // 
            this->fcgLBVppDebandThreY->AutoSize = true;
            this->fcgLBVppDebandThreY->Location = System::Drawing::Point(71, 60);
            this->fcgLBVppDebandThreY->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandThreY->Name = L"fcgLBVppDebandThreY";
            this->fcgLBVppDebandThreY->Size = System::Drawing::Size(17, 18);
            this->fcgLBVppDebandThreY->TabIndex = 70;
            this->fcgLBVppDebandThreY->Text = L"Y";
            // 
            // fcgNUVppDebandDitherC
            // 
            this->fcgNUVppDebandDitherC->Location = System::Drawing::Point(206, 88);
            this->fcgNUVppDebandDitherC->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDebandDitherC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppDebandDitherC->Name = L"fcgNUVppDebandDitherC";
            this->fcgNUVppDebandDitherC->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDebandDitherC->TabIndex = 69;
            this->fcgNUVppDebandDitherC->Tag = L"chValue";
            this->fcgNUVppDebandDitherC->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppDebandDitherY
            // 
            this->fcgNUVppDebandDitherY->Location = System::Drawing::Point(95, 88);
            this->fcgNUVppDebandDitherY->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDebandDitherY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppDebandDitherY->Name = L"fcgNUVppDebandDitherY";
            this->fcgNUVppDebandDitherY->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDebandDitherY->TabIndex = 68;
            this->fcgNUVppDebandDitherY->Tag = L"chValue";
            this->fcgNUVppDebandDitherY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppDebandThreCr
            // 
            this->fcgNUVppDebandThreCr->Location = System::Drawing::Point(318, 58);
            this->fcgNUVppDebandThreCr->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDebandThreCr->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppDebandThreCr->Name = L"fcgNUVppDebandThreCr";
            this->fcgNUVppDebandThreCr->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDebandThreCr->TabIndex = 67;
            this->fcgNUVppDebandThreCr->Tag = L"chValue";
            this->fcgNUVppDebandThreCr->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppDebandThreCb
            // 
            this->fcgNUVppDebandThreCb->Location = System::Drawing::Point(205, 58);
            this->fcgNUVppDebandThreCb->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDebandThreCb->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppDebandThreCb->Name = L"fcgNUVppDebandThreCb";
            this->fcgNUVppDebandThreCb->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDebandThreCb->TabIndex = 66;
            this->fcgNUVppDebandThreCb->Tag = L"chValue";
            this->fcgNUVppDebandThreCb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBVppDebandThreshold
            // 
            this->fcgLBVppDebandThreshold->AutoSize = true;
            this->fcgLBVppDebandThreshold->Location = System::Drawing::Point(16, 60);
            this->fcgLBVppDebandThreshold->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandThreshold->Name = L"fcgLBVppDebandThreshold";
            this->fcgLBVppDebandThreshold->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppDebandThreshold->TabIndex = 65;
            this->fcgLBVppDebandThreshold->Text = L"閾値";
            // 
            // fcgLBVppDebandRange
            // 
            this->fcgLBVppDebandRange->AutoSize = true;
            this->fcgLBVppDebandRange->Location = System::Drawing::Point(16, 29);
            this->fcgLBVppDebandRange->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDebandRange->Name = L"fcgLBVppDebandRange";
            this->fcgLBVppDebandRange->Size = System::Drawing::Size(47, 18);
            this->fcgLBVppDebandRange->TabIndex = 64;
            this->fcgLBVppDebandRange->Text = L"range";
            // 
            // fcgCXVppDebandSample
            // 
            this->fcgCXVppDebandSample->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVppDebandSample->FormattingEnabled = true;
            this->fcgCXVppDebandSample->Location = System::Drawing::Point(95, 118);
            this->fcgCXVppDebandSample->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXVppDebandSample->Name = L"fcgCXVppDebandSample";
            this->fcgCXVppDebandSample->Size = System::Drawing::Size(184, 26);
            this->fcgCXVppDebandSample->TabIndex = 63;
            this->fcgCXVppDebandSample->Tag = L"chValue";
            // 
            // fcgNUVppDebandThreY
            // 
            this->fcgNUVppDebandThreY->Location = System::Drawing::Point(95, 58);
            this->fcgNUVppDebandThreY->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDebandThreY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
            this->fcgNUVppDebandThreY->Name = L"fcgNUVppDebandThreY";
            this->fcgNUVppDebandThreY->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDebandThreY->TabIndex = 5;
            this->fcgNUVppDebandThreY->Tag = L"chValue";
            this->fcgNUVppDebandThreY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppDebandRange
            // 
            this->fcgNUVppDebandRange->Location = System::Drawing::Point(95, 26);
            this->fcgNUVppDebandRange->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDebandRange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
            this->fcgNUVppDebandRange->Name = L"fcgNUVppDebandRange";
            this->fcgNUVppDebandRange->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDebandRange->TabIndex = 4;
            this->fcgNUVppDebandRange->Tag = L"chValue";
            this->fcgNUVppDebandRange->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcggroupBoxVppDenoise
            // 
            this->fcggroupBoxVppDenoise->Controls->Add(this->fcgPNVppDenoiseKnn);
            this->fcggroupBoxVppDenoise->Controls->Add(this->fcgPNVppDenoisePmd);
            this->fcggroupBoxVppDenoise->Controls->Add(this->fcgCXVppDenoiseMethod);
            this->fcggroupBoxVppDenoise->Location = System::Drawing::Point(4, 71);
            this->fcggroupBoxVppDenoise->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppDenoise->Name = L"fcggroupBoxVppDenoise";
            this->fcggroupBoxVppDenoise->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxVppDenoise->Size = System::Drawing::Size(400, 174);
            this->fcggroupBoxVppDenoise->TabIndex = 11;
            this->fcggroupBoxVppDenoise->TabStop = false;
            this->fcggroupBoxVppDenoise->Text = L"ノイズ除去";
            // 
            // fcgPNVppDenoiseKnn
            // 
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgLBVppDenoiseKnnThreshold);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgLBVppDenoiseKnnStrength);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgLBVppDenoiseKnnRadius);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgNUVppDenoiseKnnThreshold);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgNUVppDenoiseKnnStrength);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgNUVppDenoiseKnnRadius);
            this->fcgPNVppDenoiseKnn->Location = System::Drawing::Point(4, 52);
            this->fcgPNVppDenoiseKnn->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNVppDenoiseKnn->Name = L"fcgPNVppDenoiseKnn";
            this->fcgPNVppDenoiseKnn->Size = System::Drawing::Size(282, 115);
            this->fcgPNVppDenoiseKnn->TabIndex = 65;
            // 
            // fcgLBVppDenoiseKnnThreshold
            // 
            this->fcgLBVppDenoiseKnnThreshold->AutoSize = true;
            this->fcgLBVppDenoiseKnnThreshold->Location = System::Drawing::Point(86, 82);
            this->fcgLBVppDenoiseKnnThreshold->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDenoiseKnnThreshold->Name = L"fcgLBVppDenoiseKnnThreshold";
            this->fcgLBVppDenoiseKnnThreshold->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppDenoiseKnnThreshold->TabIndex = 11;
            this->fcgLBVppDenoiseKnnThreshold->Text = L"閾値";
            // 
            // fcgLBVppDenoiseKnnStrength
            // 
            this->fcgLBVppDenoiseKnnStrength->AutoSize = true;
            this->fcgLBVppDenoiseKnnStrength->Location = System::Drawing::Point(86, 49);
            this->fcgLBVppDenoiseKnnStrength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDenoiseKnnStrength->Name = L"fcgLBVppDenoiseKnnStrength";
            this->fcgLBVppDenoiseKnnStrength->Size = System::Drawing::Size(32, 18);
            this->fcgLBVppDenoiseKnnStrength->TabIndex = 10;
            this->fcgLBVppDenoiseKnnStrength->Text = L"強さ";
            // 
            // fcgLBVppDenoiseKnnRadius
            // 
            this->fcgLBVppDenoiseKnnRadius->AutoSize = true;
            this->fcgLBVppDenoiseKnnRadius->Location = System::Drawing::Point(86, 15);
            this->fcgLBVppDenoiseKnnRadius->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDenoiseKnnRadius->Name = L"fcgLBVppDenoiseKnnRadius";
            this->fcgLBVppDenoiseKnnRadius->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppDenoiseKnnRadius->TabIndex = 9;
            this->fcgLBVppDenoiseKnnRadius->Text = L"半径";
            // 
            // fcgNUVppDenoiseKnnThreshold
            // 
            this->fcgNUVppDenoiseKnnThreshold->DecimalPlaces = 2;
            this->fcgNUVppDenoiseKnnThreshold->Location = System::Drawing::Point(161, 80);
            this->fcgNUVppDenoiseKnnThreshold->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDenoiseKnnThreshold->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUVppDenoiseKnnThreshold->Name = L"fcgNUVppDenoiseKnnThreshold";
            this->fcgNUVppDenoiseKnnThreshold->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDenoiseKnnThreshold->TabIndex = 8;
            this->fcgNUVppDenoiseKnnThreshold->Tag = L"chValue";
            this->fcgNUVppDenoiseKnnThreshold->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoiseKnnThreshold->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppDenoiseKnnStrength
            // 
            this->fcgNUVppDenoiseKnnStrength->DecimalPlaces = 2;
            this->fcgNUVppDenoiseKnnStrength->Location = System::Drawing::Point(161, 46);
            this->fcgNUVppDenoiseKnnStrength->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDenoiseKnnStrength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUVppDenoiseKnnStrength->Name = L"fcgNUVppDenoiseKnnStrength";
            this->fcgNUVppDenoiseKnnStrength->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDenoiseKnnStrength->TabIndex = 7;
            this->fcgNUVppDenoiseKnnStrength->Tag = L"chValue";
            this->fcgNUVppDenoiseKnnStrength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoiseKnnStrength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppDenoiseKnnRadius
            // 
            this->fcgNUVppDenoiseKnnRadius->Location = System::Drawing::Point(161, 12);
            this->fcgNUVppDenoiseKnnRadius->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDenoiseKnnRadius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->fcgNUVppDenoiseKnnRadius->Name = L"fcgNUVppDenoiseKnnRadius";
            this->fcgNUVppDenoiseKnnRadius->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDenoiseKnnRadius->TabIndex = 6;
            this->fcgNUVppDenoiseKnnRadius->Tag = L"chValue";
            this->fcgNUVppDenoiseKnnRadius->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoiseKnnRadius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
            // 
            // fcgPNVppDenoisePmd
            // 
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgLBVppDenoisePmdThreshold);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgLBVppDenoisePmdStrength);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgLBVppDenoisePmdApplyCount);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgNUVppDenoisePmdThreshold);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgNUVppDenoisePmdStrength);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgNUVppDenoisePmdApplyCount);
            this->fcgPNVppDenoisePmd->Location = System::Drawing::Point(4, 52);
            this->fcgPNVppDenoisePmd->Margin = System::Windows::Forms::Padding(4);
            this->fcgPNVppDenoisePmd->Name = L"fcgPNVppDenoisePmd";
            this->fcgPNVppDenoisePmd->Size = System::Drawing::Size(282, 115);
            this->fcgPNVppDenoisePmd->TabIndex = 64;
            // 
            // fcgLBVppDenoisePmdThreshold
            // 
            this->fcgLBVppDenoisePmdThreshold->AutoSize = true;
            this->fcgLBVppDenoisePmdThreshold->Location = System::Drawing::Point(86, 82);
            this->fcgLBVppDenoisePmdThreshold->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDenoisePmdThreshold->Name = L"fcgLBVppDenoisePmdThreshold";
            this->fcgLBVppDenoisePmdThreshold->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppDenoisePmdThreshold->TabIndex = 11;
            this->fcgLBVppDenoisePmdThreshold->Text = L"閾値";
            // 
            // fcgLBVppDenoisePmdStrength
            // 
            this->fcgLBVppDenoisePmdStrength->AutoSize = true;
            this->fcgLBVppDenoisePmdStrength->Location = System::Drawing::Point(86, 49);
            this->fcgLBVppDenoisePmdStrength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDenoisePmdStrength->Name = L"fcgLBVppDenoisePmdStrength";
            this->fcgLBVppDenoisePmdStrength->Size = System::Drawing::Size(32, 18);
            this->fcgLBVppDenoisePmdStrength->TabIndex = 10;
            this->fcgLBVppDenoisePmdStrength->Text = L"強さ";
            // 
            // fcgLBVppDenoisePmdApplyCount
            // 
            this->fcgLBVppDenoisePmdApplyCount->AutoSize = true;
            this->fcgLBVppDenoisePmdApplyCount->Location = System::Drawing::Point(86, 15);
            this->fcgLBVppDenoisePmdApplyCount->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppDenoisePmdApplyCount->Name = L"fcgLBVppDenoisePmdApplyCount";
            this->fcgLBVppDenoisePmdApplyCount->Size = System::Drawing::Size(36, 18);
            this->fcgLBVppDenoisePmdApplyCount->TabIndex = 9;
            this->fcgLBVppDenoisePmdApplyCount->Text = L"回数";
            // 
            // fcgNUVppDenoisePmdThreshold
            // 
            this->fcgNUVppDenoisePmdThreshold->Location = System::Drawing::Point(161, 80);
            this->fcgNUVppDenoisePmdThreshold->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDenoisePmdThreshold->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
            this->fcgNUVppDenoisePmdThreshold->Name = L"fcgNUVppDenoisePmdThreshold";
            this->fcgNUVppDenoisePmdThreshold->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDenoisePmdThreshold->TabIndex = 8;
            this->fcgNUVppDenoisePmdThreshold->Tag = L"chValue";
            this->fcgNUVppDenoisePmdThreshold->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoisePmdThreshold->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // fcgNUVppDenoisePmdStrength
            // 
            this->fcgNUVppDenoisePmdStrength->Location = System::Drawing::Point(161, 46);
            this->fcgNUVppDenoisePmdStrength->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDenoisePmdStrength->Name = L"fcgNUVppDenoisePmdStrength";
            this->fcgNUVppDenoisePmdStrength->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDenoisePmdStrength->TabIndex = 7;
            this->fcgNUVppDenoisePmdStrength->Tag = L"chValue";
            this->fcgNUVppDenoisePmdStrength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoisePmdStrength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // fcgNUVppDenoisePmdApplyCount
            // 
            this->fcgNUVppDenoisePmdApplyCount->Location = System::Drawing::Point(161, 12);
            this->fcgNUVppDenoisePmdApplyCount->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppDenoisePmdApplyCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->fcgNUVppDenoisePmdApplyCount->Name = L"fcgNUVppDenoisePmdApplyCount";
            this->fcgNUVppDenoisePmdApplyCount->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppDenoisePmdApplyCount->TabIndex = 6;
            this->fcgNUVppDenoisePmdApplyCount->Tag = L"chValue";
            this->fcgNUVppDenoisePmdApplyCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoisePmdApplyCount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
            // 
            // fcgCXVppDenoiseMethod
            // 
            this->fcgCXVppDenoiseMethod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVppDenoiseMethod->FormattingEnabled = true;
            this->fcgCXVppDenoiseMethod->Location = System::Drawing::Point(32, 22);
            this->fcgCXVppDenoiseMethod->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXVppDenoiseMethod->Name = L"fcgCXVppDenoiseMethod";
            this->fcgCXVppDenoiseMethod->Size = System::Drawing::Size(238, 26);
            this->fcgCXVppDenoiseMethod->TabIndex = 63;
            this->fcgCXVppDenoiseMethod->Tag = L"chValue";
            this->fcgCXVppDenoiseMethod->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcgCBVppResize
            // 
            this->fcgCBVppResize->AutoSize = true;
            this->fcgCBVppResize->Location = System::Drawing::Point(14, 5);
            this->fcgCBVppResize->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBVppResize->Name = L"fcgCBVppResize";
            this->fcgCBVppResize->Size = System::Drawing::Size(70, 22);
            this->fcgCBVppResize->TabIndex = 9;
            this->fcgCBVppResize->Tag = L"chValue";
            this->fcgCBVppResize->Text = L"リサイズ";
            this->fcgCBVppResize->UseVisualStyleBackColor = true;
            this->fcgCBVppResize->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcggroupBoxResize
            // 
            this->fcggroupBoxResize->Controls->Add(this->fcgCXVppResizeAlg);
            this->fcggroupBoxResize->Controls->Add(this->fcgLBVppResize);
            this->fcggroupBoxResize->Controls->Add(this->fcgNUVppResizeHeight);
            this->fcggroupBoxResize->Controls->Add(this->fcgNUVppResizeWidth);
            this->fcggroupBoxResize->Location = System::Drawing::Point(4, 5);
            this->fcggroupBoxResize->Margin = System::Windows::Forms::Padding(4);
            this->fcggroupBoxResize->Name = L"fcggroupBoxResize";
            this->fcggroupBoxResize->Padding = System::Windows::Forms::Padding(4);
            this->fcggroupBoxResize->Size = System::Drawing::Size(400, 64);
            this->fcggroupBoxResize->TabIndex = 10;
            this->fcggroupBoxResize->TabStop = false;
            // 
            // fcgCXVppResizeAlg
            // 
            this->fcgCXVppResizeAlg->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVppResizeAlg->FormattingEnabled = true;
            this->fcgCXVppResizeAlg->Location = System::Drawing::Point(212, 21);
            this->fcgCXVppResizeAlg->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXVppResizeAlg->Name = L"fcgCXVppResizeAlg";
            this->fcgCXVppResizeAlg->Size = System::Drawing::Size(179, 26);
            this->fcgCXVppResizeAlg->TabIndex = 63;
            this->fcgCXVppResizeAlg->Tag = L"chValue";
            // 
            // fcgLBVppResize
            // 
            this->fcgLBVppResize->AutoSize = true;
            this->fcgLBVppResize->Location = System::Drawing::Point(96, 26);
            this->fcgLBVppResize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBVppResize->Name = L"fcgLBVppResize";
            this->fcgLBVppResize->Size = System::Drawing::Size(16, 18);
            this->fcgLBVppResize->TabIndex = 6;
            this->fcgLBVppResize->Text = L"x";
            // 
            // fcgNUVppResizeHeight
            // 
            this->fcgNUVppResizeHeight->Location = System::Drawing::Point(119, 22);
            this->fcgNUVppResizeHeight->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppResizeHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUVppResizeHeight->Name = L"fcgNUVppResizeHeight";
            this->fcgNUVppResizeHeight->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppResizeHeight->TabIndex = 5;
            this->fcgNUVppResizeHeight->Tag = L"chValue";
            this->fcgNUVppResizeHeight->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppResizeWidth
            // 
            this->fcgNUVppResizeWidth->Location = System::Drawing::Point(14, 22);
            this->fcgNUVppResizeWidth->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUVppResizeWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUVppResizeWidth->Name = L"fcgNUVppResizeWidth";
            this->fcgNUVppResizeWidth->Size = System::Drawing::Size(75, 25);
            this->fcgNUVppResizeWidth->TabIndex = 4;
            this->fcgNUVppResizeWidth->Tag = L"chValue";
            this->fcgNUVppResizeWidth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // tabPageNVEncFeatures
            // 
            this->tabPageNVEncFeatures->Controls->Add(this->fcgTabControlFeatures);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBOSInfo);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBOSInfoLabel);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBCPUInfoOnFeatureTab);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBCPUInfoLabelOnFeatureTab);
            this->tabPageNVEncFeatures->Controls->Add(this->label2);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBGPUInfoOnFeatureTab);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBGPUInfoLabelOnFeatureTab);
            this->tabPageNVEncFeatures->Location = System::Drawing::Point(4, 28);
            this->tabPageNVEncFeatures->Margin = System::Windows::Forms::Padding(4);
            this->tabPageNVEncFeatures->Name = L"tabPageNVEncFeatures";
            this->tabPageNVEncFeatures->Size = System::Drawing::Size(762, 604);
            this->tabPageNVEncFeatures->TabIndex = 2;
            this->tabPageNVEncFeatures->Text = L"情報";
            this->tabPageNVEncFeatures->UseVisualStyleBackColor = true;
            // 
            // fcgTabControlFeatures
            // 
            this->fcgTabControlFeatures->Controls->Add(this->fcgTabPageH264);
            this->fcgTabControlFeatures->Controls->Add(this->fcgTabPageHEVC);
            this->fcgTabControlFeatures->Location = System::Drawing::Point(4, 168);
            this->fcgTabControlFeatures->Margin = System::Windows::Forms::Padding(4);
            this->fcgTabControlFeatures->Name = L"fcgTabControlFeatures";
            this->fcgTabControlFeatures->SelectedIndex = 0;
            this->fcgTabControlFeatures->Size = System::Drawing::Size(752, 430);
            this->fcgTabControlFeatures->TabIndex = 122;
            // 
            // fcgTabPageH264
            // 
            this->fcgTabPageH264->Controls->Add(this->fcgDGVFeaturesH264);
            this->fcgTabPageH264->Location = System::Drawing::Point(4, 28);
            this->fcgTabPageH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgTabPageH264->Name = L"fcgTabPageH264";
            this->fcgTabPageH264->Padding = System::Windows::Forms::Padding(4);
            this->fcgTabPageH264->Size = System::Drawing::Size(744, 398);
            this->fcgTabPageH264->TabIndex = 0;
            this->fcgTabPageH264->Text = L"H.264/AVC";
            this->fcgTabPageH264->UseVisualStyleBackColor = true;
            // 
            // fcgDGVFeaturesH264
            // 
            this->fcgDGVFeaturesH264->BackgroundColor = System::Drawing::SystemColors::Window;
            this->fcgDGVFeaturesH264->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->fcgDGVFeaturesH264->Location = System::Drawing::Point(4, 4);
            this->fcgDGVFeaturesH264->Margin = System::Windows::Forms::Padding(4);
            this->fcgDGVFeaturesH264->Name = L"fcgDGVFeaturesH264";
            this->fcgDGVFeaturesH264->RowTemplate->Height = 21;
            this->fcgDGVFeaturesH264->Size = System::Drawing::Size(735, 388);
            this->fcgDGVFeaturesH264->TabIndex = 0;
            // 
            // fcgTabPageHEVC
            // 
            this->fcgTabPageHEVC->Controls->Add(this->fcgDGVFeaturesHEVC);
            this->fcgTabPageHEVC->Location = System::Drawing::Point(4, 28);
            this->fcgTabPageHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgTabPageHEVC->Name = L"fcgTabPageHEVC";
            this->fcgTabPageHEVC->Padding = System::Windows::Forms::Padding(4);
            this->fcgTabPageHEVC->Size = System::Drawing::Size(744, 398);
            this->fcgTabPageHEVC->TabIndex = 1;
            this->fcgTabPageHEVC->Text = L"H.265/HEVC";
            this->fcgTabPageHEVC->UseVisualStyleBackColor = true;
            // 
            // fcgDGVFeaturesHEVC
            // 
            this->fcgDGVFeaturesHEVC->BackgroundColor = System::Drawing::SystemColors::Window;
            this->fcgDGVFeaturesHEVC->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->fcgDGVFeaturesHEVC->Location = System::Drawing::Point(4, 4);
            this->fcgDGVFeaturesHEVC->Margin = System::Windows::Forms::Padding(4);
            this->fcgDGVFeaturesHEVC->Name = L"fcgDGVFeaturesHEVC";
            this->fcgDGVFeaturesHEVC->RowTemplate->Height = 21;
            this->fcgDGVFeaturesHEVC->Size = System::Drawing::Size(735, 388);
            this->fcgDGVFeaturesHEVC->TabIndex = 1;
            // 
            // fcgLBOSInfo
            // 
            this->fcgLBOSInfo->AutoSize = true;
            this->fcgLBOSInfo->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBOSInfo->ForeColor = System::Drawing::Color::DarkViolet;
            this->fcgLBOSInfo->Location = System::Drawing::Point(120, 64);
            this->fcgLBOSInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBOSInfo->Name = L"fcgLBOSInfo";
            this->fcgLBOSInfo->Size = System::Drawing::Size(34, 22);
            this->fcgLBOSInfo->TabIndex = 121;
            this->fcgLBOSInfo->Text = L"OS";
            // 
            // fcgLBOSInfoLabel
            // 
            this->fcgLBOSInfoLabel->AutoSize = true;
            this->fcgLBOSInfoLabel->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBOSInfoLabel->ForeColor = System::Drawing::Color::Blue;
            this->fcgLBOSInfoLabel->Location = System::Drawing::Point(41, 61);
            this->fcgLBOSInfoLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBOSInfoLabel->Name = L"fcgLBOSInfoLabel";
            this->fcgLBOSInfoLabel->Size = System::Drawing::Size(36, 24);
            this->fcgLBOSInfoLabel->TabIndex = 120;
            this->fcgLBOSInfoLabel->Text = L"OS";
            // 
            // fcgLBCPUInfoOnFeatureTab
            // 
            this->fcgLBCPUInfoOnFeatureTab->AutoSize = true;
            this->fcgLBCPUInfoOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBCPUInfoOnFeatureTab->ForeColor = System::Drawing::Color::DarkViolet;
            this->fcgLBCPUInfoOnFeatureTab->Location = System::Drawing::Point(120, 98);
            this->fcgLBCPUInfoOnFeatureTab->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBCPUInfoOnFeatureTab->Name = L"fcgLBCPUInfoOnFeatureTab";
            this->fcgLBCPUInfoOnFeatureTab->Size = System::Drawing::Size(43, 22);
            this->fcgLBCPUInfoOnFeatureTab->TabIndex = 119;
            this->fcgLBCPUInfoOnFeatureTab->Text = L"CPU";
            // 
            // fcgLBCPUInfoLabelOnFeatureTab
            // 
            this->fcgLBCPUInfoLabelOnFeatureTab->AutoSize = true;
            this->fcgLBCPUInfoLabelOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBCPUInfoLabelOnFeatureTab->ForeColor = System::Drawing::Color::Blue;
            this->fcgLBCPUInfoLabelOnFeatureTab->Location = System::Drawing::Point(40, 95);
            this->fcgLBCPUInfoLabelOnFeatureTab->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBCPUInfoLabelOnFeatureTab->Name = L"fcgLBCPUInfoLabelOnFeatureTab";
            this->fcgLBCPUInfoLabelOnFeatureTab->Size = System::Drawing::Size(49, 24);
            this->fcgLBCPUInfoLabelOnFeatureTab->TabIndex = 118;
            this->fcgLBCPUInfoLabelOnFeatureTab->Text = L"CPU";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->label2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->label2->Location = System::Drawing::Point(18, 19);
            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(401, 24);
            this->label2->TabIndex = 117;
            this->label2->Text = L"現在の環境でサポートされる機能を表示しています。";
            // 
            // fcgLBGPUInfoOnFeatureTab
            // 
            this->fcgLBGPUInfoOnFeatureTab->AutoSize = true;
            this->fcgLBGPUInfoOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBGPUInfoOnFeatureTab->ForeColor = System::Drawing::Color::DarkViolet;
            this->fcgLBGPUInfoOnFeatureTab->Location = System::Drawing::Point(120, 131);
            this->fcgLBGPUInfoOnFeatureTab->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBGPUInfoOnFeatureTab->Name = L"fcgLBGPUInfoOnFeatureTab";
            this->fcgLBGPUInfoOnFeatureTab->Size = System::Drawing::Size(44, 22);
            this->fcgLBGPUInfoOnFeatureTab->TabIndex = 116;
            this->fcgLBGPUInfoOnFeatureTab->Text = L"GPU";
            // 
            // fcgLBGPUInfoLabelOnFeatureTab
            // 
            this->fcgLBGPUInfoLabelOnFeatureTab->AutoSize = true;
            this->fcgLBGPUInfoLabelOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBGPUInfoLabelOnFeatureTab->ForeColor = System::Drawing::Color::Blue;
            this->fcgLBGPUInfoLabelOnFeatureTab->Location = System::Drawing::Point(40, 129);
            this->fcgLBGPUInfoLabelOnFeatureTab->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBGPUInfoLabelOnFeatureTab->Name = L"fcgLBGPUInfoLabelOnFeatureTab";
            this->fcgLBGPUInfoLabelOnFeatureTab->Size = System::Drawing::Size(50, 24);
            this->fcgLBGPUInfoLabelOnFeatureTab->TabIndex = 115;
            this->fcgLBGPUInfoLabelOnFeatureTab->Text = L"GPU";
            // 
            // fcgCSExeFiles
            // 
            this->fcgCSExeFiles->ImageScalingSize = System::Drawing::Size(18, 18);
            this->fcgCSExeFiles->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fcgTSExeFileshelp });
            this->fcgCSExeFiles->Name = L"fcgCSx264";
            this->fcgCSExeFiles->Size = System::Drawing::Size(149, 28);
            // 
            // fcgTSExeFileshelp
            // 
            this->fcgTSExeFileshelp->Name = L"fcgTSExeFileshelp";
            this->fcgTSExeFileshelp->Size = System::Drawing::Size(148, 24);
            this->fcgTSExeFileshelp->Text = L"helpを表示";
            this->fcgTSExeFileshelp->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSExeFileshelp_Click);
            // 
            // fcgLBguiExBlog
            // 
            this->fcgLBguiExBlog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgLBguiExBlog->AutoSize = true;
            this->fcgLBguiExBlog->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBguiExBlog->LinkColor = System::Drawing::Color::Gray;
            this->fcgLBguiExBlog->Location = System::Drawing::Point(799, 694);
            this->fcgLBguiExBlog->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBguiExBlog->Name = L"fcgLBguiExBlog";
            this->fcgLBguiExBlog->Size = System::Drawing::Size(97, 18);
            this->fcgLBguiExBlog->TabIndex = 50;
            this->fcgLBguiExBlog->TabStop = true;
            this->fcgLBguiExBlog->Text = L"NVEncについて";
            this->fcgLBguiExBlog->VisitedLinkColor = System::Drawing::Color::Gray;
            this->fcgLBguiExBlog->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &frmConfig::fcgLBguiExBlog_LinkClicked);
            // 
            // fcgtabControlAudio
            // 
            this->fcgtabControlAudio->Controls->Add(this->fcgtabPageAudioMain);
            this->fcgtabControlAudio->Controls->Add(this->fcgtabPageAudioOther);
            this->fcgtabControlAudio->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F));
            this->fcgtabControlAudio->Location = System::Drawing::Point(776, 39);
            this->fcgtabControlAudio->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabControlAudio->Name = L"fcgtabControlAudio";
            this->fcgtabControlAudio->SelectedIndex = 0;
            this->fcgtabControlAudio->Size = System::Drawing::Size(480, 370);
            this->fcgtabControlAudio->TabIndex = 51;
            // 
            // fcgtabPageAudioMain
            // 
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioDelayCut);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioDelayCut);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudioEncTiming);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioEncTiming);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioTempDir);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgTXCustomAudioTempDir);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgBTCustomAudioTempDir);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudioUsePipe);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioBitrate);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgNUAudioBitrate);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudio2pass);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioEncMode);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioEncMode);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgBTAudioEncoderPath);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgTXAudioEncoderPath);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioEncoderPath);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudioOnly);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBFAWCheck);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioEncoder);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioEncoder);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioTemp);
            this->fcgtabPageAudioMain->Location = System::Drawing::Point(4, 27);
            this->fcgtabPageAudioMain->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabPageAudioMain->Name = L"fcgtabPageAudioMain";
            this->fcgtabPageAudioMain->Padding = System::Windows::Forms::Padding(4);
            this->fcgtabPageAudioMain->Size = System::Drawing::Size(472, 339);
            this->fcgtabPageAudioMain->TabIndex = 0;
            this->fcgtabPageAudioMain->Text = L"音声";
            this->fcgtabPageAudioMain->UseVisualStyleBackColor = true;
            // 
            // fcgCXAudioDelayCut
            // 
            this->fcgCXAudioDelayCut->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioDelayCut->FormattingEnabled = true;
            this->fcgCXAudioDelayCut->Location = System::Drawing::Point(364, 166);
            this->fcgCXAudioDelayCut->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAudioDelayCut->Name = L"fcgCXAudioDelayCut";
            this->fcgCXAudioDelayCut->Size = System::Drawing::Size(86, 26);
            this->fcgCXAudioDelayCut->TabIndex = 43;
            this->fcgCXAudioDelayCut->Tag = L"chValue";
            // 
            // fcgLBAudioDelayCut
            // 
            this->fcgLBAudioDelayCut->AutoSize = true;
            this->fcgLBAudioDelayCut->Location = System::Drawing::Point(280, 170);
            this->fcgLBAudioDelayCut->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAudioDelayCut->Name = L"fcgLBAudioDelayCut";
            this->fcgLBAudioDelayCut->Size = System::Drawing::Size(76, 18);
            this->fcgLBAudioDelayCut->TabIndex = 54;
            this->fcgLBAudioDelayCut->Text = L"ディレイカット";
            // 
            // fcgCBAudioEncTiming
            // 
            this->fcgCBAudioEncTiming->AutoSize = true;
            this->fcgCBAudioEncTiming->Location = System::Drawing::Point(302, 68);
            this->fcgCBAudioEncTiming->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgCBAudioEncTiming->Name = L"fcgCBAudioEncTiming";
            this->fcgCBAudioEncTiming->Size = System::Drawing::Size(50, 18);
            this->fcgCBAudioEncTiming->TabIndex = 53;
            this->fcgCBAudioEncTiming->Text = L"処理順";
            // 
            // fcgCXAudioEncTiming
            // 
            this->fcgCXAudioEncTiming->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioEncTiming->FormattingEnabled = true;
            this->fcgCXAudioEncTiming->Location = System::Drawing::Point(358, 64);
            this->fcgCXAudioEncTiming->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAudioEncTiming->Name = L"fcgCXAudioEncTiming";
            this->fcgCXAudioEncTiming->Size = System::Drawing::Size(84, 26);
            this->fcgCXAudioEncTiming->TabIndex = 52;
            this->fcgCXAudioEncTiming->Tag = L"chValue";
            // 
            // fcgCXAudioTempDir
            // 
            this->fcgCXAudioTempDir->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioTempDir->FormattingEnabled = true;
            this->fcgCXAudioTempDir->Location = System::Drawing::Point(169, 260);
            this->fcgCXAudioTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAudioTempDir->Name = L"fcgCXAudioTempDir";
            this->fcgCXAudioTempDir->Size = System::Drawing::Size(186, 26);
            this->fcgCXAudioTempDir->TabIndex = 46;
            this->fcgCXAudioTempDir->Tag = L"chValue";
            // 
            // fcgTXCustomAudioTempDir
            // 
            this->fcgTXCustomAudioTempDir->Location = System::Drawing::Point(80, 295);
            this->fcgTXCustomAudioTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXCustomAudioTempDir->Name = L"fcgTXCustomAudioTempDir";
            this->fcgTXCustomAudioTempDir->Size = System::Drawing::Size(305, 25);
            this->fcgTXCustomAudioTempDir->TabIndex = 47;
            this->fcgTXCustomAudioTempDir->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXCustomAudioTempDir_TextChanged);
            // 
            // fcgBTCustomAudioTempDir
            // 
            this->fcgBTCustomAudioTempDir->Location = System::Drawing::Point(395, 292);
            this->fcgBTCustomAudioTempDir->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTCustomAudioTempDir->Name = L"fcgBTCustomAudioTempDir";
            this->fcgBTCustomAudioTempDir->Size = System::Drawing::Size(36, 29);
            this->fcgBTCustomAudioTempDir->TabIndex = 49;
            this->fcgBTCustomAudioTempDir->Text = L"...";
            this->fcgBTCustomAudioTempDir->UseVisualStyleBackColor = true;
            this->fcgBTCustomAudioTempDir->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTCustomAudioTempDir_Click);
            // 
            // fcgCBAudioUsePipe
            // 
            this->fcgCBAudioUsePipe->AutoSize = true;
            this->fcgCBAudioUsePipe->Location = System::Drawing::Point(162, 168);
            this->fcgCBAudioUsePipe->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBAudioUsePipe->Name = L"fcgCBAudioUsePipe";
            this->fcgCBAudioUsePipe->Size = System::Drawing::Size(91, 22);
            this->fcgCBAudioUsePipe->TabIndex = 42;
            this->fcgCBAudioUsePipe->Tag = L"chValue";
            this->fcgCBAudioUsePipe->Text = L"パイプ処理";
            this->fcgCBAudioUsePipe->UseVisualStyleBackColor = true;
            // 
            // fcgLBAudioBitrate
            // 
            this->fcgLBAudioBitrate->AutoSize = true;
            this->fcgLBAudioBitrate->Location = System::Drawing::Point(355, 201);
            this->fcgLBAudioBitrate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAudioBitrate->Name = L"fcgLBAudioBitrate";
            this->fcgLBAudioBitrate->Size = System::Drawing::Size(41, 18);
            this->fcgLBAudioBitrate->TabIndex = 50;
            this->fcgLBAudioBitrate->Text = L"kbps";
            // 
            // fcgNUAudioBitrate
            // 
            this->fcgNUAudioBitrate->Location = System::Drawing::Point(265, 196);
            this->fcgNUAudioBitrate->Margin = System::Windows::Forms::Padding(4);
            this->fcgNUAudioBitrate->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1536, 0, 0, 0 });
            this->fcgNUAudioBitrate->Name = L"fcgNUAudioBitrate";
            this->fcgNUAudioBitrate->Size = System::Drawing::Size(81, 25);
            this->fcgNUAudioBitrate->TabIndex = 40;
            this->fcgNUAudioBitrate->Tag = L"chValue";
            this->fcgNUAudioBitrate->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgCBAudio2pass
            // 
            this->fcgCBAudio2pass->AutoSize = true;
            this->fcgCBAudio2pass->Location = System::Drawing::Point(74, 168);
            this->fcgCBAudio2pass->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBAudio2pass->Name = L"fcgCBAudio2pass";
            this->fcgCBAudio2pass->Size = System::Drawing::Size(70, 22);
            this->fcgCBAudio2pass->TabIndex = 41;
            this->fcgCBAudio2pass->Tag = L"chValue";
            this->fcgCBAudio2pass->Text = L"2pass";
            this->fcgCBAudio2pass->UseVisualStyleBackColor = true;
            this->fcgCBAudio2pass->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgCBAudio2pass_CheckedChanged);
            // 
            // fcgCXAudioEncMode
            // 
            this->fcgCXAudioEncMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioEncMode->FormattingEnabled = true;
            this->fcgCXAudioEncMode->Location = System::Drawing::Point(20, 195);
            this->fcgCXAudioEncMode->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAudioEncMode->Name = L"fcgCXAudioEncMode";
            this->fcgCXAudioEncMode->Size = System::Drawing::Size(235, 26);
            this->fcgCXAudioEncMode->TabIndex = 39;
            this->fcgCXAudioEncMode->Tag = L"chValue";
            this->fcgCXAudioEncMode->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgCXAudioEncMode_SelectedIndexChanged);
            // 
            // fcgLBAudioEncMode
            // 
            this->fcgLBAudioEncMode->AutoSize = true;
            this->fcgLBAudioEncMode->Location = System::Drawing::Point(5, 170);
            this->fcgLBAudioEncMode->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAudioEncMode->Name = L"fcgLBAudioEncMode";
            this->fcgLBAudioEncMode->Size = System::Drawing::Size(40, 18);
            this->fcgLBAudioEncMode->TabIndex = 48;
            this->fcgLBAudioEncMode->Text = L"モード";
            // 
            // fcgBTAudioEncoderPath
            // 
            this->fcgBTAudioEncoderPath->Location = System::Drawing::Point(405, 112);
            this->fcgBTAudioEncoderPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTAudioEncoderPath->Name = L"fcgBTAudioEncoderPath";
            this->fcgBTAudioEncoderPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTAudioEncoderPath->TabIndex = 38;
            this->fcgBTAudioEncoderPath->Text = L"...";
            this->fcgBTAudioEncoderPath->UseVisualStyleBackColor = true;
            this->fcgBTAudioEncoderPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTAudioEncoderPath_Click);
            // 
            // fcgTXAudioEncoderPath
            // 
            this->fcgTXAudioEncoderPath->AllowDrop = true;
            this->fcgTXAudioEncoderPath->Location = System::Drawing::Point(20, 115);
            this->fcgTXAudioEncoderPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXAudioEncoderPath->Name = L"fcgTXAudioEncoderPath";
            this->fcgTXAudioEncoderPath->Size = System::Drawing::Size(378, 25);
            this->fcgTXAudioEncoderPath->TabIndex = 37;
            this->fcgTXAudioEncoderPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXAudioEncoderPath_TextChanged);
            this->fcgTXAudioEncoderPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXAudioEncoderPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBAudioEncoderPath
            // 
            this->fcgLBAudioEncoderPath->AutoSize = true;
            this->fcgLBAudioEncoderPath->Location = System::Drawing::Point(15, 94);
            this->fcgLBAudioEncoderPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAudioEncoderPath->Name = L"fcgLBAudioEncoderPath";
            this->fcgLBAudioEncoderPath->Size = System::Drawing::Size(61, 18);
            this->fcgLBAudioEncoderPath->TabIndex = 44;
            this->fcgLBAudioEncoderPath->Text = L"～の指定";
            // 
            // fcgCBAudioOnly
            // 
            this->fcgCBAudioOnly->AutoSize = true;
            this->fcgCBAudioOnly->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgCBAudioOnly->Location = System::Drawing::Point(315, 6);
            this->fcgCBAudioOnly->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBAudioOnly->Name = L"fcgCBAudioOnly";
            this->fcgCBAudioOnly->Size = System::Drawing::Size(109, 22);
            this->fcgCBAudioOnly->TabIndex = 34;
            this->fcgCBAudioOnly->Tag = L"chValue";
            this->fcgCBAudioOnly->Text = L"音声のみ出力";
            this->fcgCBAudioOnly->UseVisualStyleBackColor = true;
            // 
            // fcgCBFAWCheck
            // 
            this->fcgCBFAWCheck->AutoSize = true;
            this->fcgCBFAWCheck->Location = System::Drawing::Point(315, 35);
            this->fcgCBFAWCheck->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBFAWCheck->Name = L"fcgCBFAWCheck";
            this->fcgCBFAWCheck->Size = System::Drawing::Size(101, 22);
            this->fcgCBFAWCheck->TabIndex = 36;
            this->fcgCBFAWCheck->Tag = L"chValue";
            this->fcgCBFAWCheck->Text = L"FAWCheck";
            this->fcgCBFAWCheck->UseVisualStyleBackColor = true;
            // 
            // fcgCXAudioEncoder
            // 
            this->fcgCXAudioEncoder->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioEncoder->FormattingEnabled = true;
            this->fcgCXAudioEncoder->Location = System::Drawing::Point(21, 42);
            this->fcgCXAudioEncoder->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAudioEncoder->Name = L"fcgCXAudioEncoder";
            this->fcgCXAudioEncoder->Size = System::Drawing::Size(214, 26);
            this->fcgCXAudioEncoder->TabIndex = 32;
            this->fcgCXAudioEncoder->Tag = L"chValue";
            this->fcgCXAudioEncoder->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgCXAudioEncoder_SelectedIndexChanged);
            // 
            // fcgLBAudioEncoder
            // 
            this->fcgLBAudioEncoder->AutoSize = true;
            this->fcgLBAudioEncoder->Location = System::Drawing::Point(6, 18);
            this->fcgLBAudioEncoder->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAudioEncoder->Name = L"fcgLBAudioEncoder";
            this->fcgLBAudioEncoder->Size = System::Drawing::Size(60, 18);
            this->fcgLBAudioEncoder->TabIndex = 33;
            this->fcgLBAudioEncoder->Text = L"エンコーダ";
            // 
            // fcgLBAudioTemp
            // 
            this->fcgLBAudioTemp->AutoSize = true;
            this->fcgLBAudioTemp->Location = System::Drawing::Point(9, 264);
            this->fcgLBAudioTemp->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAudioTemp->Name = L"fcgLBAudioTemp";
            this->fcgLBAudioTemp->Size = System::Drawing::Size(144, 18);
            this->fcgLBAudioTemp->TabIndex = 51;
            this->fcgLBAudioTemp->Text = L"音声一時ファイル出力先";
            // 
            // fcgtabPageAudioOther
            // 
            this->fcgtabPageAudioOther->Controls->Add(this->panel2);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatAfterAudioString);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatBeforeAudioString);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgBTBatAfterAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgTXBatAfterAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatAfterAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgCBRunBatAfterAudio);
            this->fcgtabPageAudioOther->Controls->Add(this->panel1);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgBTBatBeforeAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgTXBatBeforeAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatBeforeAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgCBRunBatBeforeAudio);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgCXAudioPriority);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBAudioPriority);
            this->fcgtabPageAudioOther->Location = System::Drawing::Point(4, 27);
            this->fcgtabPageAudioOther->Margin = System::Windows::Forms::Padding(4);
            this->fcgtabPageAudioOther->Name = L"fcgtabPageAudioOther";
            this->fcgtabPageAudioOther->Padding = System::Windows::Forms::Padding(4);
            this->fcgtabPageAudioOther->Size = System::Drawing::Size(472, 339);
            this->fcgtabPageAudioOther->TabIndex = 1;
            this->fcgtabPageAudioOther->Text = L"その他";
            this->fcgtabPageAudioOther->UseVisualStyleBackColor = true;
            // 
            // panel2
            // 
            this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel2->Location = System::Drawing::Point(22, 158);
            this->panel2->Margin = System::Windows::Forms::Padding(4);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(427, 1);
            this->panel2->TabIndex = 61;
            // 
            // fcgLBBatAfterAudioString
            // 
            this->fcgLBBatAfterAudioString->AutoSize = true;
            this->fcgLBBatAfterAudioString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatAfterAudioString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatAfterAudioString->Location = System::Drawing::Point(380, 260);
            this->fcgLBBatAfterAudioString->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatAfterAudioString->Name = L"fcgLBBatAfterAudioString";
            this->fcgLBBatAfterAudioString->Size = System::Drawing::Size(34, 19);
            this->fcgLBBatAfterAudioString->TabIndex = 60;
            this->fcgLBBatAfterAudioString->Text = L" 後& ";
            this->fcgLBBatAfterAudioString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgLBBatBeforeAudioString
            // 
            this->fcgLBBatBeforeAudioString->AutoSize = true;
            this->fcgLBBatBeforeAudioString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatBeforeAudioString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatBeforeAudioString->Location = System::Drawing::Point(380, 174);
            this->fcgLBBatBeforeAudioString->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatBeforeAudioString->Name = L"fcgLBBatBeforeAudioString";
            this->fcgLBBatBeforeAudioString->Size = System::Drawing::Size(34, 19);
            this->fcgLBBatBeforeAudioString->TabIndex = 51;
            this->fcgLBBatBeforeAudioString->Text = L" 前& ";
            this->fcgLBBatBeforeAudioString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgBTBatAfterAudioPath
            // 
            this->fcgBTBatAfterAudioPath->Location = System::Drawing::Point(412, 289);
            this->fcgBTBatAfterAudioPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTBatAfterAudioPath->Name = L"fcgBTBatAfterAudioPath";
            this->fcgBTBatAfterAudioPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTBatAfterAudioPath->TabIndex = 59;
            this->fcgBTBatAfterAudioPath->Tag = L"chValue";
            this->fcgBTBatAfterAudioPath->Text = L"...";
            this->fcgBTBatAfterAudioPath->UseVisualStyleBackColor = true;
            this->fcgBTBatAfterAudioPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatAfterAudioPath_Click);
            // 
            // fcgTXBatAfterAudioPath
            // 
            this->fcgTXBatAfterAudioPath->AllowDrop = true;
            this->fcgTXBatAfterAudioPath->Location = System::Drawing::Point(158, 290);
            this->fcgTXBatAfterAudioPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXBatAfterAudioPath->Name = L"fcgTXBatAfterAudioPath";
            this->fcgTXBatAfterAudioPath->Size = System::Drawing::Size(252, 25);
            this->fcgTXBatAfterAudioPath->TabIndex = 58;
            this->fcgTXBatAfterAudioPath->Tag = L"chValue";
            this->fcgTXBatAfterAudioPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatAfterAudioPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatAfterAudioPath
            // 
            this->fcgLBBatAfterAudioPath->AutoSize = true;
            this->fcgLBBatAfterAudioPath->Location = System::Drawing::Point(50, 295);
            this->fcgLBBatAfterAudioPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatAfterAudioPath->Name = L"fcgLBBatAfterAudioPath";
            this->fcgLBBatAfterAudioPath->Size = System::Drawing::Size(77, 18);
            this->fcgLBBatAfterAudioPath->TabIndex = 57;
            this->fcgLBBatAfterAudioPath->Text = L"バッチファイル";
            // 
            // fcgCBRunBatAfterAudio
            // 
            this->fcgCBRunBatAfterAudio->AutoSize = true;
            this->fcgCBRunBatAfterAudio->Location = System::Drawing::Point(22, 259);
            this->fcgCBRunBatAfterAudio->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBRunBatAfterAudio->Name = L"fcgCBRunBatAfterAudio";
            this->fcgCBRunBatAfterAudio->Size = System::Drawing::Size(254, 22);
            this->fcgCBRunBatAfterAudio->TabIndex = 55;
            this->fcgCBRunBatAfterAudio->Tag = L"chValue";
            this->fcgCBRunBatAfterAudio->Text = L"音声エンコード終了後、バッチ処理を行う";
            this->fcgCBRunBatAfterAudio->UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel1->Location = System::Drawing::Point(22, 245);
            this->panel1->Margin = System::Windows::Forms::Padding(4);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(427, 1);
            this->panel1->TabIndex = 54;
            // 
            // fcgBTBatBeforeAudioPath
            // 
            this->fcgBTBatBeforeAudioPath->Location = System::Drawing::Point(412, 205);
            this->fcgBTBatBeforeAudioPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgBTBatBeforeAudioPath->Name = L"fcgBTBatBeforeAudioPath";
            this->fcgBTBatBeforeAudioPath->Size = System::Drawing::Size(38, 29);
            this->fcgBTBatBeforeAudioPath->TabIndex = 53;
            this->fcgBTBatBeforeAudioPath->Tag = L"chValue";
            this->fcgBTBatBeforeAudioPath->Text = L"...";
            this->fcgBTBatBeforeAudioPath->UseVisualStyleBackColor = true;
            this->fcgBTBatBeforeAudioPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatBeforeAudioPath_Click);
            // 
            // fcgTXBatBeforeAudioPath
            // 
            this->fcgTXBatBeforeAudioPath->AllowDrop = true;
            this->fcgTXBatBeforeAudioPath->Location = System::Drawing::Point(158, 205);
            this->fcgTXBatBeforeAudioPath->Margin = System::Windows::Forms::Padding(4);
            this->fcgTXBatBeforeAudioPath->Name = L"fcgTXBatBeforeAudioPath";
            this->fcgTXBatBeforeAudioPath->Size = System::Drawing::Size(252, 25);
            this->fcgTXBatBeforeAudioPath->TabIndex = 52;
            this->fcgTXBatBeforeAudioPath->Tag = L"chValue";
            this->fcgTXBatBeforeAudioPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatBeforeAudioPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatBeforeAudioPath
            // 
            this->fcgLBBatBeforeAudioPath->AutoSize = true;
            this->fcgLBBatBeforeAudioPath->Location = System::Drawing::Point(50, 209);
            this->fcgLBBatBeforeAudioPath->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBBatBeforeAudioPath->Name = L"fcgLBBatBeforeAudioPath";
            this->fcgLBBatBeforeAudioPath->Size = System::Drawing::Size(77, 18);
            this->fcgLBBatBeforeAudioPath->TabIndex = 50;
            this->fcgLBBatBeforeAudioPath->Text = L"バッチファイル";
            // 
            // fcgCBRunBatBeforeAudio
            // 
            this->fcgCBRunBatBeforeAudio->AutoSize = true;
            this->fcgCBRunBatBeforeAudio->Location = System::Drawing::Point(22, 174);
            this->fcgCBRunBatBeforeAudio->Margin = System::Windows::Forms::Padding(4);
            this->fcgCBRunBatBeforeAudio->Name = L"fcgCBRunBatBeforeAudio";
            this->fcgCBRunBatBeforeAudio->Size = System::Drawing::Size(254, 22);
            this->fcgCBRunBatBeforeAudio->TabIndex = 48;
            this->fcgCBRunBatBeforeAudio->Tag = L"chValue";
            this->fcgCBRunBatBeforeAudio->Text = L"音声エンコード開始前、バッチ処理を行う";
            this->fcgCBRunBatBeforeAudio->UseVisualStyleBackColor = true;
            // 
            // fcgCXAudioPriority
            // 
            this->fcgCXAudioPriority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioPriority->FormattingEnabled = true;
            this->fcgCXAudioPriority->Location = System::Drawing::Point(195, 25);
            this->fcgCXAudioPriority->Margin = System::Windows::Forms::Padding(4);
            this->fcgCXAudioPriority->Name = L"fcgCXAudioPriority";
            this->fcgCXAudioPriority->Size = System::Drawing::Size(169, 26);
            this->fcgCXAudioPriority->TabIndex = 47;
            this->fcgCXAudioPriority->Tag = L"chValue";
            // 
            // fcgLBAudioPriority
            // 
            this->fcgLBAudioPriority->AutoSize = true;
            this->fcgLBAudioPriority->Location = System::Drawing::Point(36, 29);
            this->fcgLBAudioPriority->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->fcgLBAudioPriority->Name = L"fcgLBAudioPriority";
            this->fcgLBAudioPriority->Size = System::Drawing::Size(78, 18);
            this->fcgLBAudioPriority->TabIndex = 46;
            this->fcgLBAudioPriority->Text = L"音声優先度";
            // 
            // frmConfig
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->ClientSize = System::Drawing::Size(1260, 721);
            this->Controls->Add(this->fcgtabControlAudio);
            this->Controls->Add(this->fcgLBguiExBlog);
            this->Controls->Add(this->fcgtabControlMux);
            this->Controls->Add(this->fcgtabControlNVEnc);
            this->Controls->Add(this->fcgLBVersion);
            this->Controls->Add(this->fcgLBVersionDate);
            this->Controls->Add(this->fcgBTDefault);
            this->Controls->Add(this->fcgBTOK);
            this->Controls->Add(this->fcgBTCancel);
            this->Controls->Add(this->fcgTXCmd);
            this->Controls->Add(this->fcgtoolStripSettings);
            this->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Margin = System::Windows::Forms::Padding(4);
            this->MaximizeBox = false;
            this->Name = L"frmConfig";
            this->ShowIcon = false;
            this->Text = L"Aviutl 出力 プラグイン";
            this->Load += gcnew System::EventHandler(this, &frmConfig::frmConfig_Load);
            this->fcgtoolStripSettings->ResumeLayout(false);
            this->fcgtoolStripSettings->PerformLayout();
            this->fcgtabControlMux->ResumeLayout(false);
            this->fcgtabPageMP4->ResumeLayout(false);
            this->fcgtabPageMP4->PerformLayout();
            this->fcgtabPageMKV->ResumeLayout(false);
            this->fcgtabPageMKV->PerformLayout();
            this->fcgtabPageMPG->ResumeLayout(false);
            this->fcgtabPageMPG->PerformLayout();
            this->fcgtabPageMux->ResumeLayout(false);
            this->fcgtabPageMux->PerformLayout();
            this->fcgtabPageBat->ResumeLayout(false);
            this->fcgtabPageBat->PerformLayout();
            this->fcgtabControlNVEnc->ResumeLayout(false);
            this->tabPageVideoEnc->ResumeLayout(false);
            this->tabPageVideoEnc->PerformLayout();
            this->fcgPNHEVC->ResumeLayout(false);
            this->fcgPNHEVC->PerformLayout();
            this->fcggroupBoxColorHEVC->ResumeLayout(false);
            this->fcggroupBoxColorHEVC->PerformLayout();
            this->fcgPNBitrate->ResumeLayout(false);
            this->fcgPNBitrate->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVBRTragetQuality))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBitrate))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUMaxkbps))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNULookaheadDepth))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAQStrength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVBVBufsize))->EndInit();
            this->fcgGroupBoxAspectRatio->ResumeLayout(false);
            this->fcgGroupBoxAspectRatio->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioY))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioX))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNURefFrames))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBframes))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUGopLength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoEnabled))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoDisabled))->EndInit();
            this->fcgPNH264->ResumeLayout(false);
            this->fcgPNH264->PerformLayout();
            this->fcggroupBoxColorH264->ResumeLayout(false);
            this->fcggroupBoxColorH264->PerformLayout();
            this->fcgPNQP->ResumeLayout(false);
            this->fcgPNQP->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPI))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPP))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPB))->EndInit();
            this->tabPageVideoDetail->ResumeLayout(false);
            this->tabPageVideoDetail->PerformLayout();
            this->fcgGroupBoxQulaityStg->ResumeLayout(false);
            this->groupBoxQPDetail->ResumeLayout(false);
            this->groupBoxQPDetail->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPInitB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPInitP))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPInitI))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMinB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMinP))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMinI))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMaxB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMaxP))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPMaxI))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUSlices))->EndInit();
            this->fcgPNH264Detail->ResumeLayout(false);
            this->fcgPNH264Detail->PerformLayout();
            this->fcgPNHEVCDetail->ResumeLayout(false);
            this->fcgPNHEVCDetail->PerformLayout();
            this->tabPageExOpt->ResumeLayout(false);
            this->tabPageExOpt->PerformLayout();
            this->fcggroupBoxVppTweak->ResumeLayout(false);
            this->fcggroupBoxVppTweak->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakHue))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakSaturation))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakGamma))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakContrast))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppTweakBrightness))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakGamma))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakSaturation))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakHue))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakContrast))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppTweakBrightness))->EndInit();
            this->fcggroupBoxVppDetailEnahance->ResumeLayout(false);
            this->fcgPNVppEdgelevel->ResumeLayout(false);
            this->fcgPNVppEdgelevel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelWhite))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelThreshold))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelBlack))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppEdgelevelStrength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
            this->fcgPNVppUnsharp->ResumeLayout(false);
            this->fcgPNVppUnsharp->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppUnsharpThreshold))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppUnsharpWeight))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppUnsharpRadius))->EndInit();
            this->fcggroupBoxVppAfs->ResumeLayout(false);
            this->fcggroupBoxVppAfs->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreCMotion))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreYMotion))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreDeint))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsThreShift))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsCoeffShift))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsRight))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsLeft))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsBottom))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsUp))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgTBVppAfsMethodSwitch))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreCMotion))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreShift))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreDeint))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsThreYMotion))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsCoeffShift))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppAfsMethodSwitch))->EndInit();
            this->fcggroupBoxVppDeband->ResumeLayout(false);
            this->fcggroupBoxVppDeband->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandDitherC))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandDitherY))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandThreCr))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandThreCb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandThreY))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDebandRange))->EndInit();
            this->fcggroupBoxVppDenoise->ResumeLayout(false);
            this->fcgPNVppDenoiseKnn->ResumeLayout(false);
            this->fcgPNVppDenoiseKnn->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnThreshold))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnStrength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnRadius))->EndInit();
            this->fcgPNVppDenoisePmd->ResumeLayout(false);
            this->fcgPNVppDenoisePmd->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdThreshold))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdStrength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdApplyCount))->EndInit();
            this->fcggroupBoxResize->ResumeLayout(false);
            this->fcggroupBoxResize->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeHeight))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeWidth))->EndInit();
            this->tabPageNVEncFeatures->ResumeLayout(false);
            this->tabPageNVEncFeatures->PerformLayout();
            this->fcgTabControlFeatures->ResumeLayout(false);
            this->fcgTabPageH264->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesH264))->EndInit();
            this->fcgTabPageHEVC->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesHEVC))->EndInit();
            this->fcgCSExeFiles->ResumeLayout(false);
            this->fcgtabControlAudio->ResumeLayout(false);
            this->fcgtabPageAudioMain->ResumeLayout(false);
            this->fcgtabPageAudioMain->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAudioBitrate))->EndInit();
            this->fcgtabPageAudioOther->ResumeLayout(false);
            this->fcgtabPageAudioOther->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        delegate void SetEnvironmentInfoDelegate();
        String^ StrCPUInfo;
        String^ StrGPUInfo;
        SetEnvironmentInfoDelegate ^getEnvironmentInfoDelegate;

        nvfeature_t featureCache;
        DataTable^ dataTableNVEncFeaturesH264;
        DataTable^ dataTableNVEncFeaturesHEVC;
        
        
        const SYSTEM_DATA *sys_dat;
        CONF_GUIEX *conf;
        LocalSettings LocalStg;
        bool CurrentPipeEnabled;
        bool stgChanged;
        String^ CurrentStgDir;
        ToolStripMenuItem^ CheckedStgMenuItem;
        CONF_GUIEX *cnf_stgSelected;
        String^ lastQualityStr;
#ifdef HIDE_MPEG2
        TabPage^ tabPageMpgMux;
#endif
    private:
        System::Int32 GetCurrentAudioDefaultBitrate();
        delegate System::Void qualityTimerChangeDelegate();
        System::Void InitComboBox();
        System::Void setAudioDisplay();
        System::Void AudioEncodeModeChanged();
        System::Void InitStgFileList();
        System::Void RebuildStgFileDropDown(String^ stgDir);
        System::Void RebuildStgFileDropDown(ToolStripDropDownItem^ TS, String^ dir);
        System::Void SetLocalStg();
        System::Void LoadLocalStg();
        System::Void SaveLocalStg();
        System::Boolean CheckLocalStg();
        System::Void SetTXMaxLen(TextBox^ TX, int max_len);
        System::Void SetTXMaxLenAll();
        System::Void InitForm();
        System::Void ConfToFrm(CONF_GUIEX *cnf);
        System::Void FrmToConf(CONF_GUIEX *cnf);
        System::Void SetChangedEvent(Control^ control, System::EventHandler^ _event);
        System::Void SetAllCheckChangedEvents(Control ^top);
        System::Void SaveToStgFile(String^ stgName);
        System::Void DeleteStgFile(ToolStripMenuItem^ mItem);
        System::Boolean EnableSettingsNoteChange(bool Enable);
        System::Void fcgTSLSettingsNotes_DoubleClick(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSTSettingsNotes_Leave(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSTSettingsNotes_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
        System::Void fcgTSTSettingsNotes_TextChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void GetfcgTSLSettingsNotes(char *notes, int nSize);
        System::Void SetfcgTSLSettingsNotes(const char *notes);
        System::Void SetfcgTSLSettingsNotes(String^ notes);
        System::Void fcgTSBSave_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSBSaveNew_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSBDelete_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSSettings_DropDownItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e);
        System::Void UncheckAllDropDownItem(ToolStripItem^ mItem);
        ToolStripMenuItem^ fcgTSSettingsSearchItem(String^ stgPath, ToolStripItem^ mItem);
        ToolStripMenuItem^ fcgTSSettingsSearchItem(String^ stgPath);
        System::Void CheckTSSettingsDropDownItem(ToolStripMenuItem^ mItem);
        System::Void CheckTSItemsEnabled(CONF_GUIEX *current_conf);
        System::Void fcgChangeMuxerVisible(System::Object^  sender, System::EventArgs^  e);
        System::Void SetHelpToolTips();
        System::Void ShowExehelp(String^ ExePath, String^ args);
        System::Void fcgTSBOtherSettings_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgChangeEnabled(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSBBitrateCalc_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void CloseBitrateCalc();
        System::Void SetfbcBTABEnable(bool enable, int max);
        System::Void SetfbcBTVBEnable(bool enable);
        System::Void fcgCBAudio2pass_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgCXAudioEncoder_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgCXAudioEncMode_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void AdjustLocation();
        System::Void ActivateToolTip(bool Enable);
        System::Void SetStgEscKey(bool Enable);
        System::Void SetToolStripEvents(ToolStrip^ TS, System::Windows::Forms::MouseEventHandler^ _event);
        System::Void SetEnvironmentInfo();
        System::Void SetupFeatureTable();
        System::Void fcgCodecChanged(System::Object^  sender, System::EventArgs^  e);
    public:
        System::Void InitData(CONF_GUIEX *set_config, const SYSTEM_DATA *system_data);
        System::Void SetVideoBitrate(int bitrate);
        System::Void SetAudioBitrate(int bitrate);
        System::Void InformfbcClosed();
    private:
        System::Void fcgTSItem_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
            EnableSettingsNoteChange(false);
        }
    private:
        System::Void frmConfig_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
            if (e->KeyCode == Keys::Escape)
                this->Close();
        }
    private:
        System::Void NUSelectAll(System::Object^  sender, System::EventArgs^  e) {
             NumericUpDown^ NU = dynamic_cast<NumericUpDown^>(sender);
             NU->Select(0, NU->Text->Length);
         }
    private:
        System::Void setComboBox(ComboBox^ CX, const X264_OPTION_STR * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i].desc; i++)
                CX->Items->Add(String(list[i].desc).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setComboBox(ComboBox^ CX, const CX_DESC * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i].desc; i++)
                CX->Items->Add(String(list[i].desc).ToString());
            CX->EndUpdate();
        }
    private:
        template<size_t size>
        System::Void setComboBox(ComboBox^ CX, const guid_desc (&list)[size]) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; i < size; i++)
                CX->Items->Add(String(list[i].desc).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setComboBox(ComboBox^ CX, const char * const * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i]; i++)
                CX->Items->Add(String(list[i]).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setComboBox(ComboBox^ CX, const WCHAR * const * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i]; i++)
                CX->Items->Add(String(list[i]).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setPriorityList(ComboBox^ CX) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; priority_table[i].text; i++)
                CX->Items->Add(String(priority_table[i].text).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setMuxerCmdExNames(ComboBox^ CX, int muxer_index) {
            CX->BeginUpdate();
            CX->Items->Clear();
            MUXER_SETTINGS *mstg = &sys_dat->exstg->s_mux[muxer_index];
            for (int i = 0; i < mstg->ex_count; i++)
                CX->Items->Add(String(mstg->ex_cmd[i].name).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setAudioEncoderNames() {
            fcgCXAudioEncoder->BeginUpdate();
            fcgCXAudioEncoder->Items->Clear();
            //fcgCXAudioEncoder->Items->AddRange(reinterpret_cast<array<String^>^>(LocalStg.audEncName->ToArray(String::typeid)));
            fcgCXAudioEncoder->Items->AddRange(LocalStg.audEncName->ToArray());
            fcgCXAudioEncoder->EndUpdate();
        }
    private:
        System::Void TX_LimitbyBytes(System::Object^  sender, System::ComponentModel::CancelEventArgs^ e) {
            int maxLength = 0;
            int stringBytes = 0;
            TextBox^ TX = nullptr;
            if ((TX = dynamic_cast<TextBox^>(sender)) == nullptr)
                return;
            stringBytes = CountStringBytes(TX->Text);
            maxLength = TX->MaxLength;
            if (stringBytes > maxLength - 1) {
                e->Cancel = true;
                MessageBox::Show(this, L"入力された文字数が多すぎます。減らしてください。", L"エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    private:
        System::Boolean openExeFile(TextBox^ TX, String^ ExeName) {
            //WinXPにおいて、OpenFileDialogはCurrentDirctoryを勝手に変更しやがるので、
            //一度保存し、あとから再適用する
            String^ CurrentDir = Directory::GetCurrentDirectory();
            OpenFileDialog ofd;
            ofd.Multiselect = false;
            ofd.FileName = ExeName;
            ofd.Filter = MakeExeFilter(ExeName);
            if (Directory::Exists(LocalStg.LastAppDir))
                ofd.InitialDirectory = Path::GetFullPath(LocalStg.LastAppDir);
            else if (File::Exists(TX->Text))
                ofd.InitialDirectory = Path::GetFullPath(Path::GetDirectoryName(TX->Text));
            else
                ofd.InitialDirectory = String(sys_dat->aviutl_dir).ToString();
            bool ret = (ofd.ShowDialog() == System::Windows::Forms::DialogResult::OK);
            if (ret) {
                if (sys_dat->exstg->s_local.get_relative_path)
                    ofd.FileName = GetRelativePath(ofd.FileName, CurrentDir);
                LocalStg.LastAppDir = Path::GetDirectoryName(Path::GetFullPath(ofd.FileName));
                TX->Text = ofd.FileName;
                TX->SelectionStart = TX->Text->Length;
            }
            Directory::SetCurrentDirectory(CurrentDir);
            return ret;
        }
    private: 
        System::Void fcgBTMP4MuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMP4MuxerPath, LocalStg.MP4MuxerExeName);
        }
    private: 
        System::Void fcgBTTC2MP4Path_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXTC2MP4Path, LocalStg.TC2MP4ExeName);
        }
    private:
        System::Void fcgBTMP4RawMuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMP4RawPath, LocalStg.MP4RawExeName);
        }
    private: 
        System::Void fcgBTAudioEncoderPath_Click(System::Object^  sender, System::EventArgs^  e) {
            int index = fcgCXAudioEncoder->SelectedIndex;
            openExeFile(fcgTXAudioEncoderPath, LocalStg.audEncExeName[index]);
        }
    private: 
        System::Void fcgBTMKVMuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMKVMuxerPath, LocalStg.MKVMuxerExeName);
        }
    private:
        System::Void fcgBTMPGMuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMPGMuxerPath, LocalStg.MPGMuxerExeName);
        }
    private:
        System::Void openTempFolder(TextBox^ TX) {
            FolderBrowserDialog^ fbd = fcgfolderBrowserTemp;
            if (Directory::Exists(TX->Text))
                fbd->SelectedPath = TX->Text;
            if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                if (sys_dat->exstg->s_local.get_relative_path)
                    fbd->SelectedPath = GetRelativePath(fbd->SelectedPath);
                TX->Text = fbd->SelectedPath;
                TX->SelectionStart = TX->Text->Length;
            }
        }
    private: 
        System::Void fcgBTCustomAudioTempDir_Click(System::Object^  sender, System::EventArgs^  e) {
            openTempFolder(fcgTXCustomAudioTempDir);
        }
    private: 
        System::Void fcgBTMP4BoxTempDir_Click(System::Object^  sender, System::EventArgs^  e) {
            openTempFolder(fcgTXMP4BoxTempDir);
        }
    private: 
        System::Void fcgBTCustomTempDir_Click(System::Object^  sender, System::EventArgs^  e) {
            openTempFolder(fcgTXCustomTempDir);
        }
    private:
        System::Boolean openAndSetFilePath(TextBox^ TX, String^ fileTypeName) {
            return openAndSetFilePath(TX, fileTypeName, nullptr, nullptr);
        }
    private:
        System::Boolean openAndSetFilePath(TextBox^ TX, String^ fileTypeName, String^ ext) {
            return openAndSetFilePath(TX, fileTypeName, ext, nullptr);
        }
    private:
        System::Boolean openAndSetFilePath(TextBox^ TX, String^ fileTypeName, String^ ext, String^ dir) {
            //WinXPにおいて、OpenFileDialogはCurrentDirctoryを勝手に変更しやがるので、
            //一度保存し、あとから再適用する
            String^ CurrentDir = Directory::GetCurrentDirectory();
            //設定
            if (ext == nullptr)
                ext = L".*";
            OpenFileDialog^ ofd = fcgOpenFileDialog;
            ofd->FileName = L"";
            if (dir != nullptr && Directory::Exists(dir))
                ofd->InitialDirectory = dir;
            if (TX->Text->Length) {
                String^ fileName = nullptr;
                try {
                    fileName = Path::GetFileName(TX->Text);
                } catch (...) {
                    //invalid charによる例外は破棄
                }
                if (fileName != nullptr)
                    ofd->FileName = fileName;
            }
            ofd->Multiselect = false;
            ofd->Filter = fileTypeName + L"(*" + ext + L")|*" + ext;
            bool ret = (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK);
            if (ret) {
                if (sys_dat->exstg->s_local.get_relative_path)
                    ofd->FileName = GetRelativePath(ofd->FileName, CurrentDir);
                TX->Text = ofd->FileName;
                TX->SelectionStart = TX->Text->Length;
            }
            Directory::SetCurrentDirectory(CurrentDir);
            return ret;
        }
    private:
        System::Void fcgBTBatAfterPath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatAfterPath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatAfterPath->Text);
        }
    private:
        System::Void fcgBTBatBeforePath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatBeforePath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatBeforePath->Text);
        }
    private:
        System::Void fcgBTBatBeforeAudioPath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatBeforeAudioPath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatBeforeAudioPath->Text);
        }
    private:
        System::Void fcgBTBatAfterAudioPath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatAfterAudioPath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatAfterAudioPath->Text);
        }
    private:
        System::Void SetCXIndex(ComboBox^ CX, int index) {
            CX->SelectedIndex = clamp(index, 0, CX->Items->Count - 1);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, Decimal d) {
            NU->Value = clamp(d, NU->Minimum, NU->Maximum);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, int i) {
            NU->Value = clamp(Convert::ToDecimal(i), NU->Minimum, NU->Maximum);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, unsigned int i) {
            NU->Value = clamp(Convert::ToDecimal(i), NU->Minimum, NU->Maximum);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, float f) {
            NU->Value = clamp(Convert::ToDecimal(f), NU->Minimum, NU->Maximum);
        }
    private: 
        System::Void frmConfig_Load(System::Object^  sender, System::EventArgs^  e) {
            InitForm();
        }
    private: 
        System::Void fcgBTOK_Click(System::Object^  sender, System::EventArgs^  e) {
            if (CheckLocalStg())
                return;
            init_CONF_GUIEX(conf, false);
            FrmToConf(conf);
            SaveLocalStg();
            ZeroMemory(conf->oth.notes, sizeof(conf->oth.notes));
            this->Close();
        }
    private: 
        System::Void fcgBTCancel_Click(System::Object^  sender, System::EventArgs^  e) {
            this->Close();
        }
    private: 
        System::Void fcgBTDefault_Click(System::Object^  sender, System::EventArgs^  e) {
            init_CONF_GUIEX(conf, FALSE);
            ConfToFrm(conf);
        }
    private:
        System::Void ChangePresetNameDisplay(bool changed) {
            if (CheckedStgMenuItem != nullptr) {
                fcgTSSettings->Text = (changed) ? L"[" + CheckedStgMenuItem->Text + L"]*" : CheckedStgMenuItem->Text;
                fcgTSBSave->Enabled = changed;
            }
        }
    private:
        System::Void CheckOtherChanges(System::Object^  sender, System::EventArgs^  e) {
            if (CheckedStgMenuItem == nullptr)
                return;
            CONF_GUIEX check_change;
            init_CONF_GUIEX(&check_change, FALSE);
            FrmToConf(&check_change);
            ChangePresetNameDisplay(memcmp(&check_change, cnf_stgSelected, sizeof(CONF_GUIEX)) != 0);
        }
    private: 
        System::Void fcgTXCmd_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
            int offset = (fcgTXCmd->Multiline) ? -fcgTXCmdfulloffset : fcgTXCmdfulloffset;
            fcgTXCmd->Height += offset;
            this->Height += offset;
            fcgTXCmd->Multiline = !fcgTXCmd->Multiline;
        }
    private: 
        System::Void fcgTSSettings_Click(System::Object^  sender, System::EventArgs^  e) {
            if (EnableSettingsNoteChange(false))
                fcgTSSettings->ShowDropDown();
        }
    private: 
        System::Void fcgTXAudioEncoderPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.audEncPath[fcgCXAudioEncoder->SelectedIndex] = fcgTXAudioEncoderPath->Text;
            fcgBTAudioEncoderPath->ContextMenuStrip = (File::Exists(fcgTXAudioEncoderPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXMP4MuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MP4MuxerPath = fcgTXMP4MuxerPath->Text;
            fcgBTMP4MuxerPath->ContextMenuStrip = (File::Exists(fcgTXMP4MuxerPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXTC2MP4Path_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.TC2MP4Path = fcgTXTC2MP4Path->Text;
            fcgBTTC2MP4Path->ContextMenuStrip = (File::Exists(fcgTXTC2MP4Path->Text)) ? fcgCSExeFiles : nullptr;
        }
    private:
        System::Void fcgTXMP4RawMuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MP4RawPath = fcgTXMP4RawPath->Text;
            fcgBTMP4RawPath->ContextMenuStrip = (File::Exists(fcgTXMP4RawPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXMKVMuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MKVMuxerPath = fcgTXMKVMuxerPath->Text;
            fcgBTMKVMuxerPath->ContextMenuStrip = (File::Exists(fcgTXMKVMuxerPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private:
        System::Void fcgTXMPGMuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MPGMuxerPath = fcgTXMPGMuxerPath->Text;
            fcgBTMPGMuxerPath->ContextMenuStrip = (File::Exists(fcgTXMPGMuxerPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXMP4BoxTempDir_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.CustomMP4TmpDir = fcgTXMP4BoxTempDir->Text;
        }
    private: 
        System::Void fcgTXCustomAudioTempDir_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.CustomAudTmpDir = fcgTXCustomAudioTempDir->Text;
        }
    private: 
        System::Void fcgTXCustomTempDir_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.CustomTmpDir = fcgTXCustomTempDir->Text;
        }
    private:
        System::Void fcgSetDragDropFilename_Enter(System::Object^  sender, DragEventArgs^  e) {
            e->Effect = (e->Data->GetDataPresent(DataFormats::FileDrop)) ? DragDropEffects::Copy : DragDropEffects::None;
        }
    private:
        System::Void fcgSetDragDropFilename_DragDrop(System::Object^  sender, DragEventArgs^  e) {
            TextBox^ TX = dynamic_cast<TextBox^>(sender);
            array<System::String ^>^ filelist = dynamic_cast<array<System::String ^>^>(e->Data->GetData(DataFormats::FileDrop, false));
            if (filelist == nullptr || TX == nullptr)
                return;
            String^ filePath = filelist[0]; //複数だった場合は先頭のものを使用
            if (sys_dat->exstg->s_local.get_relative_path)
                filePath = GetRelativePath(filePath);
            TX->Text = filePath;
        }
    private:
        System::Void fcgTSExeFileshelp_Click(System::Object^  sender, System::EventArgs^  e) {
            System::Windows::Forms::ToolStripMenuItem^ TS = dynamic_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
            if (TS == nullptr) return;
            System::Windows::Forms::ContextMenuStrip^ CS = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(TS->Owner);
            if (CS == nullptr) return;

            //Name, args, Path の順番
            array<ExeControls>^ ControlList = {
                { fcgBTAudioEncoderPath->Name,   fcgTXAudioEncoderPath->Text,   sys_dat->exstg->s_aud[fcgCXAudioEncoder->SelectedIndex].cmd_help },
                { fcgBTMP4MuxerPath->Name,       fcgTXMP4MuxerPath->Text,       sys_dat->exstg->s_mux[MUXER_MP4].help_cmd },
                { fcgBTTC2MP4Path->Name,         fcgTXTC2MP4Path->Text,         sys_dat->exstg->s_mux[MUXER_TC2MP4].help_cmd },
                { fcgBTMP4RawPath->Name,         fcgTXMP4RawPath->Text,         sys_dat->exstg->s_mux[MUXER_MP4_RAW].help_cmd },
                { fcgBTMKVMuxerPath->Name,       fcgTXMKVMuxerPath->Text,       sys_dat->exstg->s_mux[MUXER_MKV].help_cmd },
                { fcgBTMPGMuxerPath->Name,       fcgTXMPGMuxerPath->Text,       sys_dat->exstg->s_mux[MUXER_MPG].help_cmd }
            };
            for (int i = 0; i < ControlList->Length; i++) {
                if (NULL == String::Compare(CS->SourceControl->Name, ControlList[i].Name)) {
                    ShowExehelp(ControlList[i].Path, String(ControlList[i].args).ToString());
                    return;
                }
            }
            MessageBox::Show(L"ヘルプ表示用のコマンドが設定されていません。", L"エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    private:
        System::Void fcgLBguiExBlog_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
            fcgLBguiExBlog->LinkVisited = true;
            try {
                System::Diagnostics::Process::Start(String(sys_dat->exstg->blog_url).ToString());
            } catch (...) {
                //いちいちメッセージとか出さない
            };
        }
    private:
        System::Void fcgBTQualityStg_Click(System::Object^  sender, System::EventArgs^  e) {
            if (NULL == featureCache)
                return;
            CONF_GUIEX cnf;
            FrmToConf(&cnf);
            auto presetList = nvfeature_GetCachedNVEncCapability(featureCache);
            memcpy(&cnf.nvenc.enc_config, &presetList[fcgCXEncCodec->SelectedIndex].presetConfigs[fcgCXQualityPreset->SelectedIndex].presetCfg, sizeof(cnf.nvenc.enc_config));
            if (cnf.nvenc.enc_config.gopLength == UINT32_MAX) {
                cnf.nvenc.enc_config.gopLength = 0;
                cnf.nvenc.enc_config.encodeCodecConfig.h264Config.idrPeriod = 0;
                cnf.nvenc.enc_config.encodeCodecConfig.hevcConfig.idrPeriod = 0;
            }
            cnf.nvenc.codecConfig[fcgCXEncCodec->SelectedIndex] = cnf.nvenc.enc_config.encodeCodecConfig;
            //cnf.nvenc.enc_config.encodeCodecConfig.h264Config.sliceModeData = 1;
            //cnf.nvenc.enc_config.encodeCodecConfig.hevcConfig.sliceMode     = 0;
            //cnf.nvenc.enc_config.encodeCodecConfig.hevcConfig.sliceModeData = 0;
            ConfToFrm(&cnf);
        }
    private:
        System::Void fcgTBVppAfsScroll(System::Object^  sender, System::EventArgs^  e) {
            System::Windows::Forms::TrackBar^ senderTB = dynamic_cast<System::Windows::Forms::TrackBar^>(sender);
            if (senderTB == nullptr) return;

            array<TrackBarNU>^ targetList = {
                { fcgTBVppAfsMethodSwitch, fcgNUVppAfsMethodSwitch },
                { fcgTBVppAfsCoeffShift,   fcgNUVppAfsCoeffShift },
                { fcgTBVppAfsThreShift,    fcgNUVppAfsThreShift },
                { fcgTBVppAfsThreDeint,    fcgNUVppAfsThreDeint },
                { fcgTBVppAfsThreYMotion, fcgNUVppAfsThreYMotion },
                { fcgTBVppAfsThreCMotion, fcgNUVppAfsThreCMotion }
            };
            for (int i = 0; i < targetList->Length; i++) {
                if (NULL == String::Compare(senderTB->Name, targetList[i].TB->Name)) {
                    SetNUValue(targetList[i].NU, senderTB->Value);
                    return;
                }
            }
        }
    private:
        System::Void fcgNUVppAfsValueChanged(System::Object^  sender, System::EventArgs^  e) {
            System::Windows::Forms::NumericUpDown^ senderNU = dynamic_cast<System::Windows::Forms::NumericUpDown^>(sender);
            if (senderNU == nullptr) return;

            array<TrackBarNU>^ targetList = {
                { fcgTBVppAfsMethodSwitch, fcgNUVppAfsMethodSwitch },
                { fcgTBVppAfsCoeffShift,   fcgNUVppAfsCoeffShift },
                { fcgTBVppAfsThreShift,    fcgNUVppAfsThreShift },
                { fcgTBVppAfsThreDeint,    fcgNUVppAfsThreDeint },
                { fcgTBVppAfsThreYMotion,  fcgNUVppAfsThreYMotion },
                { fcgTBVppAfsThreCMotion,  fcgNUVppAfsThreCMotion }
            };
            for (int i = 0; i < targetList->Length; i++) {
                if (NULL == String::Compare(senderNU->Name, targetList[i].NU->Name)) {
                    targetList[i].TB->Value = (int)senderNU->Value;
                    return;
                }
            }
        }
    private:
        System::Void fcgTBVppTweakScroll(System::Object^  sender, System::EventArgs^  e) {
            System::Windows::Forms::TrackBar^ senderTB = dynamic_cast<System::Windows::Forms::TrackBar^>(sender);
            if (senderTB == nullptr) return;

            array<TrackBarNU>^ targetList = {
                { fcgTBVppTweakBrightness, fcgNUVppTweakBrightness },
                { fcgTBVppTweakContrast,   fcgNUVppTweakContrast },
                { fcgTBVppTweakGamma,      fcgNUVppTweakGamma },
                { fcgTBVppTweakSaturation, fcgNUVppTweakSaturation },
                { fcgTBVppTweakHue,        fcgNUVppTweakHue }
            };
            for (int i = 0; i < targetList->Length; i++) {
                if (NULL == String::Compare(senderTB->Name, targetList[i].TB->Name)) {
                    SetNUValue(targetList[i].NU, senderTB->Value);
                    return;
                }
            }
        }
    private:
        System::Void fcgNUVppTweakValueChanged(System::Object^  sender, System::EventArgs^  e) {
            System::Windows::Forms::NumericUpDown^ senderNU = dynamic_cast<System::Windows::Forms::NumericUpDown^>(sender);
            if (senderNU == nullptr) return;

            array<TrackBarNU>^ targetList = {
                { fcgTBVppTweakBrightness, fcgNUVppTweakBrightness },
                { fcgTBVppTweakContrast,   fcgNUVppTweakContrast },
                { fcgTBVppTweakGamma,      fcgNUVppTweakGamma },
                { fcgTBVppTweakSaturation, fcgNUVppTweakSaturation },
                { fcgTBVppTweakHue,        fcgNUVppTweakHue }
            };
            for (int i = 0; i < targetList->Length; i++) {
                if (NULL == String::Compare(senderNU->Name, targetList[i].NU->Name)) {
                    targetList[i].TB->Value = (int)senderNU->Value;
                    return;
                }
            }
        }
};
}
