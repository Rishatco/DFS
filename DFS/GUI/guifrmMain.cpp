#include "guifrmMain.h"


guifrmMain::guifrmMain( wxWindow* parent )
:
frmMain( parent )
{
	matr.resize(50, std::vector<int>(50, 0));
}

void guifrmMain::create_node(wxMouseEvent& even)
{
	char c[100];
	
	
	if (versh == -1) {
		for (int i = 0; i < n; i++) {
		
			if ((even.GetX() < koordtch[i].first + 20) && (even.GetX() > koordtch[i].first - 20) && even.GetY() < koordtch[i].second + 20 && even.GetY() > koordtch[i].second - 20) {
				versh = i;
				break;
			}
		}
	}
	else {
		int toversh = -1;
		
		for (int i = 0; i < n; i++)

			if(even.GetX() < koordtch[i].first + 20 && even.GetX() > koordtch[i].first - 20 && even.GetY() < koordtch[i].second +20 && even.GetY() > koordtch[i].second - 20) {
				toversh = i;
				break;
			}
		if ((toversh != -1) && (versh != toversh)) {
			wxClientDC dc(m_panel2);
			wxColor col;
			col.SetRGB(0xff0000);
			wxPen pen;
			pen.SetWidth(2);
			pen.SetColour(col);
			dc.SetPen(pen);
			int weight = 1;
			char c[100];
			dc.DrawLine({koordtch[versh].first,koordtch[versh].second }, { koordtch[toversh].first,koordtch[toversh].second });
			if (m_radioBtn1->GetValue()) {
				wxNumberEntryDialog dialog(this, wxT(""), wxT("Enter a weight:"), wxT("Weight"), 1, 1, 100); if (dialog.ShowModal() == wxID_OK) {  weight = dialog.GetValue(); }
				dialog.Show();
				
				_itoa(weight, c,10);
				col.SetRGB(0xffffff);
				pen.SetWidth(10);
				dc.SetPen(pen);
				dc.DrawText(c, (koordtch[versh].first + koordtch[toversh].first) / 2 + 7, (koordtch[versh].second + koordtch[toversh].second) / 2 - 7);
			
			}
			if (m_radioBtn1->GetValue()) {
				adj->SetCellValue(versh, toversh, c);
				adj->SetCellValue(toversh, versh, c);
			}
			else
			{
				adj->SetCellValue(versh, toversh, '1');
				adj->SetCellValue(toversh, versh, '1');
			}
			matr[versh][toversh] = weight;
			matr[toversh][versh] = weight;
			versh = -1;
		}
	}
	
	
}

void guifrmMain::create_nodes(wxMouseEvent& even)
{
	wxClientDC dc(m_panel2);
	wxColor col;
	col.SetRGB(0xffffff);
	wxPen pen;
	pen.SetWidth(10);
	pen.SetColour(col);
	dc.SetPen(pen);
	char c[100];
	_itoa(n + 1, c, 10);
	dc.DrawText(c, { even.GetX() + 15, even.GetY() });
	koordtch[n] = { even.GetX(),even.GetY() };
	n++;
	adj->AppendCols();
	adj->AppendRows();
	for (int i = 0; i < n; i++) {
		char d[100];
		_itoa(i+1, d, 10);
		adj->SetColLabelValue(i, d);
		adj->SetRowLabelValue(i, d);
	}
	
	col.SetRGB(0xff0000);
	
	pen.SetWidth(2);
	pen.SetColour(col);
	dc.SetPen(pen);
	dc.SetBrush(*wxBLUE_BRUSH);
	dc.DrawCircle({ even.GetX(),even.GetY() }, 10);
	
	
}
std::vector<std::vector<int>>matr2;
void guifrmMain::euler_click(wxCommandEvent& event)
{
	bool flag=true;

	for (int i = 0; i < n; i++) {
		int col = 0;
		for (int j = 0; j < n; j++)
			if (matr[i][j])
				col++;
		if (col % 2 ==1) { flag = false; break; }
	}
	paint();
	if (flag) {
		matr2 = matr;
		search(0);
	}
	else {
		wxMessageDialog* dial = new wxMessageDialog(NULL,
			 wxT("Graph hasn't euler cycle"), wxT("Message"), wxOK);
		dial->ShowModal();
	}
}

void guifrmMain::search(int v) {
	
	
	wxClientDC dc(m_panel2);
	wxColor col;
	col.SetRGB(0x0000ff);
	wxPen pen;
	pen.SetWidth(2);
	pen.SetColour(col);
	dc.SetPen(pen);
	dc.SetBrush(*wxRED_BRUSH);
	for(int i=0;i<n;i++)
		if (matr2[v][i])
		{
			//wxMilliSleep(100);
			//dc.DrawCircle(koordtch[v].first, koordtch[v].second, 10);
			matr2[v][i]--;
			matr2[i][v]--;
			//wxMilliSleep(100);
			//dc.DrawLine(koordtch[v].first, koordtch[v].second, koordtch[i].first, koordtch[i].second);
			//wxMilliSleep(100);
			//dc.DrawCircle(koordtch[i].first, koordtch[i].second, 10);
			//wxMilliSleep(100);
			search(i);
		}
	
	col.SetRGB(0x0000ff);
	pen.SetWidth(2);
	pen.SetColour(col);
	dc.SetPen(pen);
	dc.SetBrush(*wxBLACK_BRUSH);
	
	wxMilliSleep(300);
	path.push_back(v);
	if (path.size() >= 2) {

		dc.DrawLine(koordtch[v].first, koordtch[v].second, koordtch[path[path.size()-2]].first, koordtch[path[path.size() - 2]].second);
		wxMilliSleep(300);
	}
	dc.DrawCircle(koordtch[v].first, koordtch[v].second, 10);
}

void guifrmMain::clean(wxCommandEvent& event)
{
	wxClientDC dc(m_panel2);
	dc.Clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			adj->SetCellValue(i, j, "");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr[i][j] = 0;
	for (int i = 0; i < n; i++)
		used[i] = 0;
	n = 0;
}

void guifrmMain::start_dfs(wxCommandEvent& event)
{
	paint();
	for (int i = 0; i < n; i++)used[i] = false;
	int cur_vers =atoi( m_textCtrl2->GetValue());
	cur_vers--;
	dfs( cur_vers);

}

void guifrmMain::dfs( int v)
{
	used[v] = true;
	wxClientDC dc(m_panel2);
	wxColor col;
	col.SetRGB(0x0000ff);
	wxPen pen;
	pen.SetWidth(2);
	pen.SetColour(col);
	dc.SetPen(pen);
	dc.SetBrush(*wxRED_BRUSH);
	dc.DrawCircle(koordtch[v].first,koordtch[v].second, 10);
	wxSleep(1);
	for (int i = 0; i < n; i++) {
		if (!used[i] && matr[v][i]) {
			pen.SetWidth(2);
			pen.SetColour(col);
			dc.SetPen(pen);
			dc.DrawLine({ koordtch[v].first,koordtch[v].second }, { koordtch[i].first,koordtch[i].second });
			wxSleep(1);
			dfs(i);

		}

	}



}
std::vector<std::vector<int>>matr3;
void guifrmMain::short_path(wxCommandEvent& event)
{

	wxClientDC dc(m_panel2);
	wxColor col;
	col.SetRGB(0x0000ff);
	wxPen pen;
	pen.SetWidth(2);
	pen.SetColour(col);
	dc.SetPen(pen);
	dc.SetBrush(*wxRED_BRUSH);
	matr3 = matr;
	std::vector<int> b;
	for (int i = 0; i < n; i++)
		used[i] = false;
	path.clear();
	path.resize(n);
	for (int i = 0; i < n; i++)
		path[i] = i;
	int start_vers = atoi(m_textCtrl2->GetValue());
	int end_vers = atoi(m_textCtrl3->GetValue());
	start_vers--;
	end_vers--;
	b = matr3[start_vers];
	used[start_vers] = 1;
	path[start_vers] = 0;
	dc.DrawCircle(koordtch[start_vers].first, koordtch[start_vers].second, 10);
	for (int j = 0; j < n; j++) {
		int v = NULL;
		for (int i = 0; i < n; i++)
			if (!used[i] && (v == NULL || path[i] < path[v]))
				v = i;
		dc.DrawLine(koordtch[v].first, koordtch[v].second, koordtch[start_vers].first, koordtch[start_vers].second);
		wxMilliSleep(500);
		dc.DrawCircle(koordtch[v].first, koordtch[v].second,10);
		wxMilliSleep(500);
		used[v] = 1;
		for (int i = 0; i < n; i++) {
			if (b[i] > b[v] + matr3[v][i]) {
				b[i] =  b[v] + matr3[v][i];
				dc.DrawLine(koordtch[v].first, koordtch[v].second, koordtch[i].first, koordtch[i].second );
				wxMilliSleep(500);
				path[i] = v;
			}
		}
	}
	char buffer[100];
	_itoa(b[end_vers], buffer, 10);
	wxMessageDialog* dial = new wxMessageDialog(NULL,
		wxT("Short path"), buffer, wxOK);
	dial->ShowModal();
}

void guifrmMain::paint()
{
	wxClientDC dc(m_panel2);
	wxColor col;
	col.SetRGB(0xff0000);
	wxPen pen;
	pen.SetWidth(2);
	pen.SetColour(col);
	
	dc.SetPen(pen);
	dc.SetBrush(*wxBLUE_BRUSH);
	for (int i = 0; i < n; i++) {
		dc.DrawCircle(koordtch[i].first,koordtch[i].second,10);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matr[i][j])
				dc.DrawLine(koordtch[i].first, koordtch[i].second, koordtch[j].first, koordtch[j].second);



}


