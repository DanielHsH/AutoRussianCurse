/****************************************************************************/
/***************************    RussianCurse.cpp    *************************/
/****************************************************************************/

#include "stdafx.h"
#include "RussianCurse.h"
#include "RussianCurseDlg.h"
#include "globalPreDefines.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/****************************************************************************/
/************************** About Dialog ************************************/
/****************************************************************************/

/*class CAboutDlg : public CDialog {
public:
	    CAboutDlg();

	    enum { IDD = IDD_ABOUTBOX };

	protected:
	    virtual void DoDataExchange(CDataExchange* pDX);
	    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD){
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// CRussianCurseDlg dialog


/****************************************************************************/
/******************************** Main Dialog *******************************/
/****************************************************************************/

// Initialize variables and load icon
CRussianCurseDlg::CRussianCurseDlg(CWnd* pParent)
	: CDialog(CRussianCurseDlg::IDD, pParent){

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

/****************************************************************************/
// Define data exchange between variables and GUI components
void CRussianCurseDlg::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_TITLE_COMBO     ,c_title);
	DDX_Control(pDX,IDC_WHO_COMBO		,c_who);
	DDX_Control(pDX,IDC_DOWHAT_COMBO	,c_doWhat);
	DDX_Control(pDX,IDC_WHERE_COMBO	    ,c_doWhere);
	DDX_Control(pDX,IDC_andWhat_COMBO   ,c_andWhat);
	DDX_Control(pDX,IDC_WITH_COMBO      ,c_with);
	DDX_Control(pDX,IDC_FUTURE_COMBO    ,c_future);
	DDX_Control(pDX,IDC_ULTI_COMBO      ,c_ulti);
	DDX_Control(pDX,IDC_EXCLA_COMBO     ,c_excla);
	DDX_Control(pDX,IDC_LAUGH_COMBO     ,c_laugh);
	
	DDX_Text   (pDX,IDC_EDIT_CURSE		,curseText);
}

/****************************************************************************/
// Map callback functions to GUI components

BEGIN_MESSAGE_MAP(CRussianCurseDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CURSE, &CRussianCurseDlg::OnBnClickedCurse)
	ON_BN_CLICKED(IDC_RAND, &CRussianCurseDlg::OnBnClickedRand)
	ON_CBN_SELCHANGE(IDC_TITLE_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_WHO_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_DOWHAT_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_WHERE_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_andWhat_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_WITH_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_FUTURE_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_ULTI_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_EXCLA_COMBO, &CRussianCurseDlg::OnCbnComboChange)
	ON_CBN_SELCHANGE(IDC_LAUGH_COMBO, &CRussianCurseDlg::OnCbnComboChange)
END_MESSAGE_MAP()


/****************************************************************************/
// Dialog Initialization

BOOL CRussianCurseDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL){
	}

    // Disable Windows maximize button
	ModifyStyle(WS_MAXIMIZEBOX, 0);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	int i;

	// -----------------------------------------------
	// Insert do title values

	i = 0;
	Title[i].heb = "�� ����";					Title[i++].rus = "Ah ti Pidor,";
	Title[i].heb = "�� ������, �����";			Title[i++].rus = "Ebis v jopu, Negr!";
	Title[i].heb = "����� �����";				Title[i++].rus = "Podhvati spid gnida.";
	Title[i].heb = "�����";						Title[i++].rus = "Ei Barabanchik,";
	Title[i].heb = "������ ���";				Title[i++].rus = "Da ti viserok,";
	Title[i].heb = "���� ����";					Title[i++].rus = "Ti Yojik v tumane,";
	Title[i].heb = "����������";				Title[i++].rus = "Yob tvoyu mat i vobche";
	Title[i].heb = "����� ������";				Title[i++].rus = "Sys-Admin srani,";
	Title[i].heb = "�����";						Title[i++].rus = "Bliad!";
	Title[i].heb = "����� ����";				Title[i++].rus = "Yobani Nasos,";
	Title[i].heb = "�� ��� ���";				Title[i++].rus = "Idi suda suka,";
	Title[i].heb = "�� ����";					Title[i++].rus = "Ti jertva aborta,";

	titleSize = i;
	for (i = 0; i <titleSize; i++){
		c_title.InsertString(i,Title[i].heb);
	}
	c_title.SetCurSel(0);

	// -----------------------------------------------
	// Insert who values

	i = 0;
	Who[i].heb = "��� ���";				Who[i++].rus = "Mat' tvoya";
	Who[i].heb = "���� �������";		Who[i++].rus = "Tvoya urodlivaia jena";
	Who[i].heb = "���� ���";			Who[i++].rus = "Tvoya babka";
	Who[i].heb = "����-��-��� ���";		Who[i++].rus = "Tvoya zalupa";
	Who[i].heb = "����";				Who[i++].rus = "Tvoya tyotya";
	Who[i].heb = "���� ���";			Who[i++].rus = "Tvoya dusha";
	Who[i].heb = "�� ����";				Who[i++].rus = "Tvoya plemianitsa";
	Who[i].heb = "��� �'����";			Who[i++].rus = "Sestra Ivana";
	Who[i].heb = "��� �������";			Who[i++].rus = "Tvoya preiomnaia doch";

	whoSize = i;
	for (i = 0; i <whoSize; i++){
		c_who.InsertString(i,Who[i].heb);
	}
	c_who.SetCurSel(0);

	// -----------------------------------------------
	// Insert do what values

	i = 0;
	doWhat[i].heb = "�����";				doWhat[i++].rus = "konchaet";
	doWhat[i].heb = "�����";				doWhat[i++].rus = "sidit";
	doWhat[i].heb = "������";				doWhat[i++].rus = "mochitsia";
	doWhat[i].heb = "�����";				doWhat[i++].rus = "skachet";
	doWhat[i].heb = "������";				doWhat[i++].rus = "drochit";
	doWhat[i].heb = "����� �� �����";		doWhat[i++].rus = "kovilyaet";
	doWhat[i].heb = "�����";				doWhat[i++].rus = "tantzuet";
	doWhat[i].heb = "�����";				doWhat[i++].rus = "ebiotsia";
	doWhat[i].heb = "�����";				doWhat[i++].rus = "krichit";
	doWhat[i].heb = "�����";				doWhat[i++].rus = "vopit";

	whatSize = i;
	for (i = 0; i <whatSize; i++){
		c_doWhat.InsertString(i,doWhat[i].heb);
	}
	c_doWhat.SetCurSel(0);

	// -----------------------------------------------
	// Insert do where values

	i = 0;
	doWhere[i].heb = "�� �������";			doWhere[i++].rus = "na lijah";
	doWhere[i].heb = "�� ��";				doWhere[i++].rus = "na dereve";
	doWhere[i].heb = "������ ����";			doWhere[i++].rus = "s vetrom";
	doWhere[i].heb = "�������";				doWhere[i++].rus = "v vanne";
	doWhere[i].heb = "�� ��� ������";		doWhere[i++].rus = "s paroi obosranih svinei";
	doWhere[i].heb = "�����";				doWhere[i++].rus = "v voenkomate";
	doWhere[i].heb = "�� ����";				doWhere[i++].rus = "na sebia";
	doWhere[i].heb = "�������";				doWhere[i++].rus = "v Moskve stolitce";
	doWhere[i].heb = "���� ������";			doWhere[i++].rus = "v kosmose";
	doWhere[i].heb = "���� ��� ����";		doWhere[i++].rus = "v T-34";
	doWhere[i].heb = "����";				doWhere[i++].rus = "na narah v sebire";
	doWhere[i].heb = "�� �'����";			doWhere[i++].rus = "s iobanim gruzinom";

	whereSize = i;
	for (i = 0; i <whereSize; i++){
		c_doWhere.InsertString(i,doWhere[i].heb);
	}
	c_doWhere.SetCurSel(0);

	// -----------------------------------------------
	// Insert do where values

	i = 0;
	andWhat[i].heb = "�����";				andWhat[i++].rus = "i vstavliaet";
	andWhat[i].heb = "����� ���";			andWhat[i++].rus = "i puskaiet sluni na";
	andWhat[i].heb = "�����";				andWhat[i++].rus = "i nuhaet";
	andWhat[i].heb = "�����";				andWhat[i++].rus = "i jriot";
	andWhat[i].heb = "����� ��";			andWhat[i++].rus = "i ublajaet";
	andWhat[i].heb = "����� �";			    andWhat[i++].rus = "i sosiot";
	andWhat[i].heb = "����� ������";	    andWhat[i++].rus = "i visiraet ne po detski";
	andWhat[i].heb = "����� ����";			andWhat[i++].rus = "i niriaet v";
	andWhat[i].heb = "������ ��";			andWhat[i++].rus = "i fantaziroet pro";
	andWhat[i].heb = "�����";				andWhat[i++].rus = "i lijet";
	andWhat[i].heb = "������ ��";			andWhat[i++].rus = "i perdit v";

	andWhatSize = i;
	for (i = 0; i <andWhatSize; i++){
		c_andWhat.InsertString(i,andWhat[i].heb);
	}
	c_andWhat.SetCurSel(0);

	// -----------------------------------------------
	// Insert do with values

	i = 0;
	With[i].heb = "���� ����� ����";		With[i++].rus = "praporchika iz stroibata";
	With[i].heb = "����";					With[i++].rus = "holodilnik";
	With[i].heb = "����� ����";				With[i++].rus = "jelezni shlagbaum";
	With[i].heb = "��� �� ���";				With[i++].rus = "govno tigra";
	With[i].heb = "�� ���";					With[i++].rus = "parashu na dvore";
	With[i].heb = "��� ����� ���";			With[i++].rus = "moio levoe eitso";
	With[i].heb = "���� �����";				With[i++].rus = "opticheskuiu mishku";
	With[i].heb = "����� ����";				With[i++].rus = "rozavi vibrator";
	With[i].heb = "�����";					With[i++].rus = "basheni kran";
	With[i].heb = "����� ����� ����";		With[i++].rus = "100 gram sivuhi";
	With[i].heb = "�����";					With[i++].rus = "passport";
	With[i].heb = "��� ��� �� ����";		With[i++].rus = "gniloe salo";

	withSize = i;
	for (i = 0; i <withSize; i++){
		c_with.InsertString(i,With[i].heb);
	}
	c_with.SetCurSel(0);

	// -----------------------------------------------
	// Insert future plans values

	i = 0;
	Future[i].heb = "�� ������ �� �����";			Future[i++].rus = "Poshol ti nahui chmo";
	Future[i].heb = "�� ����� ������ ������";		Future[i++].rus = "Idi chetai zviozdina nebe";
	Future[i].heb = "�� ����� ���������";			Future[i++].rus = "Nakormis sasisochkoi do upada";
	Future[i].heb = "�� ���� ����������� �� �����";	Future[i++].rus = "A nu chitai psichoanalizu Freida";
	Future[i].heb = "����� ����� ����� ���";		Future[i++].rus = "Rodis obratno";
	Future[i].heb = "�� ����� ����� ����� ����";	Future[i++].rus = "Ed na bazar za linoksom, lohotron";
	Future[i].heb = "���� ������ �� ��� �����";		Future[i++].rus = "Vali ohotitsia na golovastikov";
	Future[i].heb = "����� ����� ������";			Future[i++].rus = "Sleisia v unitaz";
	Future[i].heb = "�� ����� ������� �� ��� ����";	Future[i++].rus = "Pizdui davit ejei goloi jopoi";
	Future[i].heb = "���� ���� ���� ���� �� ����";	Future[i++].rus = "Davai otbivai yablocko bashkoi ob stolb";
	Future[i].heb = "����� �� ��� �� ��������";		Future[i++].rus = "Zavali s pradedom Gitlera i Stalina";
	Future[i].heb = "�� ����� �� �������� ����";	Future[i++].rus = "Potris ob dinozavra, starichio";

	futureSize = i;
	for (i = 0; i <futureSize; i++){
		c_future.InsertString(i,Future[i].heb);
	}
	c_future.SetCurSel(0);

	// -----------------------------------------------
	// Insert ultimatum values

	i = 0;
	Ulti[i].heb = "���� ���� ����";					Ulti[i++].rus = "a ne to ubiu ";
	Ulti[i].heb = "��� �� �����, ����� ����";		Ulti[i++].rus = "a budesh pizdet, propetushu ";
	Ulti[i].heb = "���� ���� ���� �� ���� �����";	Ulti[i++].rus = "ili vari sup srediskoi i baklojanami ";
	Ulti[i].heb = "���� ����� ���� �����";			Ulti[i++].rus = "a esli net to sdam vtsirk ";
	Ulti[i].heb = "���� ����� ���� ����";			Ulti[i++].rus = "a ne to uroiu ";
	Ulti[i].heb = "���� ����� ����� ��� ������";	Ulti[i++].rus = "i bud prokliat vsemi zekami v adu ";
	Ulti[i].heb = "�� ����� �� ��� ����";			Ulti[i++].rus = "a mojet sasi hui i ne psihui ";
	Ulti[i].heb = "�� ������ ���� �����";			Ulti[i++].rus = "ili skrutis v ovalnoe govno ";
	Ulti[i].heb = "���� ���� ������� �� ���� �����";Ulti[i++].rus = "a ne to budesh tochit napilnik do vozrojdenia Lenina ";
	Ulti[i].heb = "���� ���� ����� ���� �� ���";	Ulti[i++].rus = ", smotri u menia - obosru ne vilizesh ";
	Ulti[i].heb = "--- ��� ���� ---";				Ulti[i++].rus = "";

	ultiSize = i;
	for (i = 0; i <ultiSize; i++){
		c_ulti.InsertString(i,Ulti[i].heb);
	}
	c_ulti.SetCurSel(0);

	// -----------------------------------------------
	// Insert excla values

	i = 0;
	Excla[i].heb = "����";							Excla[i++].rus = ",nahui.";
	Excla[i].heb = "�����";							Excla[i++].rus = ",bliad.";
	Excla[i].heb = "?���� �� �� ����";				Excla[i++].rus = ",ti ponial?!";
	Excla[i].heb = "����";							Excla[i++].rus = ",vjopu!";
	Excla[i].heb = "�������";						Excla[i++].rus = ",pizdets...";
	Excla[i].heb = "����";							Excla[i++].rus = ",voobche!";
	Excla[i].heb = "���� ���";						Excla[i++].rus = "- i eto pravda!";
	Excla[i].heb = "����� ���������� ������ ���";	Excla[i++].rus = "- i daje pingvini tverdiat eto poutram.";
	Excla[i].heb = "--- ��� ���� ����� ---";	    Excla[i++].rus = ".";

	exclaSize = i;
	for (i = 0; i <exclaSize; i++){
		c_excla.InsertString(i,Excla[i].heb);
	}
	c_excla.SetCurSel(0);

	// -----------------------------------------------
	// Insert Evil laugh values

	i = 0;
	Laugh[i].heb = "�� �� ��";							Laugh[i++].rus = "Ha ha ha...";
	Laugh[i].heb = "�� �� ��";							Laugh[i++].rus = "Hi hi hi...";
	Laugh[i].heb = "....�����";							Laugh[i++].rus = "Pffff... Loh...";
	Laugh[i].heb = "�����-�����";						Laugh[i++].rus = "Ebat kopat...";
	Laugh[i].heb = "!����� ����";						Laugh[i++].rus = "Kazu na vozu! A....";
	Laugh[i].heb = "--- ��� ���� ---";					Laugh[i++].rus = "";

	laughSize = i;
	for (i = 0; i <laughSize; i++){
		c_laugh.InsertString(i,Laugh[i].heb);
	}
	c_laugh.SetCurSel(0);

	// -----------------------------------------------
	// -----------------------------------------------

	// Update the GUI using the initialized values
	UpdateData(false);
	srand ((int)time(NULL));
	OnBnClickedRand();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

/****************************************************************************/
// System command (from menu) handler

void CRussianCurseDlg::OnSysCommand(UINT nID, LPARAM lParam){
/*	if ((nID & 0xFFF0) == IDM_ABOUTBOX){
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else{*/
		CDialog::OnSysCommand(nID, lParam);
/*	}*/
}

/****************************************************************************/
// Dialog paint

void CRussianCurseDlg::OnPaint(){
	if (IsIconic()){
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else{
		CDialog::OnPaint();
	}
}

/****************************************************************************/
// Dragging minimized window
// The system calls this function to obtain the cursor to display while the user drags
// the minimized window.
HCURSOR CRussianCurseDlg::OnQueryDragIcon(){
	return static_cast<HCURSOR>(m_hIcon);
}

/****************************************************************************/
/*************************** CallBack Handlers ******************************/
/****************************************************************************/

void CRussianCurseDlg::ConstructCurse(){
	curseText = "";
	curseText.Append(Title[c_title.GetCurSel()].rus);
	curseText.Append(_T(" "));
	curseText.Append(Who   [c_who   .GetCurSel()].rus);
	curseText.Append(_T(" "));
	curseText.Append(doWhat[c_doWhat.GetCurSel()].rus);
	curseText.Append(_T(" "));
	curseText.Append(doWhere[c_doWhere.GetCurSel()].rus);
	curseText.Append(_T(" "));
	curseText.Append(andWhat[c_andWhat.GetCurSel()].rus);
	curseText.Append(_T(" "));
	curseText.Append(With[c_with.GetCurSel()].rus);
	curseText.Append(_T("! "));
	curseText.Append(Future[c_future.GetCurSel()].rus);
	curseText.Append(_T(" "));
	curseText.Append(Ulti[c_ulti.GetCurSel()].rus);
	//curseText.Append(_T(" "));
	curseText.Append(Excla[c_excla.GetCurSel()].rus);
	curseText.Append(_T(" "));
	curseText.Append(Laugh[c_laugh.GetCurSel()].rus);
	curseText.Append(_T(" "));

	UpdateData(false);
}

/****************************************************************************/

void CRussianCurseDlg::OnBnClickedCurse(){
	ConstructCurse();
}

/****************************************************************************/

void CRussianCurseDlg::OnCbnComboChange(){
	ConstructCurse();
}


/****************************************************************************/

#define changeComboRand(combo,maxSize) (combo.SetCurSel((combo.GetCurSel() + rand()%(maxSize  -1) + 1 )%maxSize))

void CRussianCurseDlg::OnBnClickedRand(){
	// Chose random values which are all diffrent from the previous values.
	// In fact choose randomly only the delta
	c_title  .SetCurSel((c_title  .GetCurSel() + rand()%(titleSize  -1) + 1 )%titleSize);
	c_who    .SetCurSel((c_who    .GetCurSel() + rand()%(whoSize    -1) + 1 )%whoSize);
	c_doWhat .SetCurSel((c_doWhat .GetCurSel() + rand()%(whatSize   -1) + 1 )%whatSize);
	c_doWhere.SetCurSel((c_doWhere.GetCurSel() + rand()%(whereSize  -1) + 1 )%whereSize);
	c_andWhat.SetCurSel((c_andWhat.GetCurSel() + rand()%(andWhatSize-1) + 1 )%andWhatSize);
	c_with	 .SetCurSel((c_with	  .GetCurSel() + rand()%(withSize   -1) + 1 )%withSize);
	c_future .SetCurSel((c_future .GetCurSel() + rand()%(futureSize -1) + 1 )%futureSize);
	c_ulti	 .SetCurSel((c_ulti	  .GetCurSel() + rand()%(ultiSize   -1) + 1 )%ultiSize);
	c_excla  .SetCurSel((c_excla  .GetCurSel() + rand()%(exclaSize  -1) + 1 )%exclaSize);
	changeComboRand(c_laugh,laughSize);
	UpdateData(false);
	ConstructCurse();
}

/****************************************************************************/
// EOF.

