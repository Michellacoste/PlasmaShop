#ifndef _VAULTSHOP_MAIN_H
#define _VAULTSHOP_MAIN_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTabWidget>
#include <QAction>

#include <Vault/plVaultStore.h>
#include <SDL/plSDLMgr.h>
#include <list>

#include "QVaultNode.h"

class VaultShopMain : public QMainWindow {
public:
    enum TreeRoles {
        kRoleNodeID = Qt::UserRole
    };

private:
    Q_OBJECT
    QTreeWidget* fVaultTree;
    QTabWidget* fNodeEditor;
    QVaultNode* fVaultNodeEditor;

    // Menu actions
    enum {
        kFileOpenVault, kFileSaveVault, kFileExit, kVaultOpenNode,
        kNodeUnLink, kNodeLink, kNodeCreate, kNodeUnsubscribe,
        kNumActions
    };
    QAction* fActions[kNumActions];

    // libPlasma stuff
    struct VaultInfo {
        plVaultStore* fVault;
        QString fVaultFile;
        QTreeWidgetItem* fRootItem;

        VaultInfo(QString filename);
        ~VaultInfo();
        void save();
    };
    std::list<VaultInfo*> fLoadedVaults;
    plSDLMgr fSDLMgr;

public:
    VaultShopMain();
    virtual ~VaultShopMain();
    void loadVault(QString filename, QString vaultName);
    void loadNode(const plVaultNode& node, QTreeWidgetItem* parent, VaultInfo* vault);

signals:
    void nodeChanged(unsigned int nodeId);

protected:
    virtual void closeEvent(QCloseEvent* evt);
    VaultInfo* findCurrentVault(QTreeWidgetItem* item = NULL);
    QList<QTreeWidgetItem*> findNodeItems(unsigned int nodeId, QTreeWidgetItem* parent);
    plVaultNode saveNode(QTreeWidgetItem* nodeItem);
    void updateNode(QTreeWidgetItem* item, const plVaultNode& node);

public slots:
    void openGame();
    void performSave();
    void openNode();
    void treeItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
    void treeContextMenu(const QPoint& pos);
    void unlinkNode();
    void linkNode();
    void createNode();
    void closeNode();
    void refreshNode(unsigned int nodeId);
};

#endif
