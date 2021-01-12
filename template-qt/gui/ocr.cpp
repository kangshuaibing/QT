#include "ocr.h"
#include "ui_ocr.h"
#include "checkboxheaderview.h"

OCR::OCR(QWidget *parent) :QWidget(parent),ui(new Ui::OCR)
{
    initializeUi();
}

OCR::~OCR()
{
    delete ui;
}
void OCR::initializeUi()
{
     ui->setupUi(this);

     setAttribute(Qt::WA_StyledBackground);
     QStringList headerText;
     headerText <<""<<"医院项目名称" << "医保项目名称" << "单价" << "数量" << "金额" << "类别" << "限价" << "拒付金额"<<"备注";
     QStringList listItem;
     listItem <<"心电图" << "心电图" << "10" << "1" << "10" << "甲类" << "15" << "10"<<" ";

    ui->tableWidget->setColumnCount((headerText.count()));
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(headerText);


    CheckBoxHeaderView * checkHeaderView = new CheckBoxHeaderView(0, QPoint(0 , 0),QSize(20 , 20 ), Qt::Horizontal, this);
    checkHeaderView->setObjectName(QStringLiteral("checkHeaderView"));
    ui->tableWidget->setHorizontalHeader( checkHeaderView );

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格宽度

    //行数据
    for(int i =0;i<10;i++)
    {
        QTableWidgetItem *item;
        QCheckBox *CheckBox ;
        for(int j =1;j<10;j++)
        {
            item = new QTableWidgetItem(listItem.at(j-1),0);
            ui->tableWidget->setItem(i,j,item);

            CheckBox = new QCheckBox();
            QSize size(20, 20);
            CheckBox->setFixedSize(size);
            CheckBox->setCheckState(Qt::Unchecked);

            ui->tableWidget->setCellWidget(i, 0, CheckBox);//row行，0列
        }
    }
    ui->tableWidget->show();

    //绑定信号和槽，然后就可以实现全选功能了
    //connect(checkHeaderView, &CheckBoxHeaderView::checkStatusChange, this, &frmReport::slotCheckStatusChange);


     //创建单击选中的信号槽连接


}
