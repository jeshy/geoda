/**
 * GeoDa TM, Copyright (C) 2011-2015 by Luc Anselin - all rights reserved
 *
 * This file is part of GeoDa.
 * 
 * GeoDa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GeoDa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEODA_CENTER_TSNE_DLG_H__
#define __GEODA_CENTER_TSNE_DLG_H__

#include <map>
#include <vector>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "../VarTools.h"
#include "../Explore/AnimatePlotCanvas.h"
#include "AbstractClusterDlg.h"
#include "../Algorithms/tsne.h"


class TSNEDlg : public AbstractClusterDlg
{
public:
    TSNEDlg(wxFrame *parent, Project* project);
    virtual ~TSNEDlg();
    
    void CreateControls();
    
    void OnOK( wxCommandEvent& event );
    void OnCloseClick( wxCommandEvent& event );
    void OnClose(wxCloseEvent& ev);
    void OnSeedCheck(wxCommandEvent& event);
    void OnChangeSeed(wxCommandEvent& event);
    void InitVariableCombobox(wxListBox* var_box);
    void OnSlider(wxCommandEvent& ev);
    void OnSave( wxCommandEvent& event );
    virtual wxString _printConfiguration();
    double _calculateRankCorr(const std::vector<std::vector<double> >& result);

    std::vector<GdaVarTools::VarInfo> var_info;
    std::vector<int> col_ids;

    static AnimatePlotcanvas* m_animate;
    static SimpleReportTextCtrl* m_textbox;
    static wxButton* saveButton;
    static wxSlider* m_slider;
    static double final_cost;
    static double rank_corr;
    static std::string report;
    static std::string old_report;
    static char dist;

protected:
    long max_iteration;
    int last_iter;
    double *data ;
    double* Y;
    double **ragged_distances;
    TSNE *tsne;
    boost::thread *tsne_job;

    wxChoice* m_distance;
    wxChoice* combo_n;


    wxTextCtrl* txt_iteration;
    wxTextCtrl* txt_perplexity;
    wxTextCtrl* txt_theta;
    wxTextCtrl* txt_momentum;
    wxTextCtrl* txt_min_cost;
    wxTextCtrl* txt_finalmomentum;
    wxTextCtrl* txt_mom_switch_iter;
    wxTextCtrl* txt_learningrate;

    wxCheckBox* chk_seed;
    wxButton* seedButton;

    wxStaticText* lbl_poweriteration;
    DECLARE_EVENT_TABLE()
    
};

#endif
